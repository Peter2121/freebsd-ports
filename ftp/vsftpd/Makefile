PORTNAME=	vsftpd
PORTVERSION=	3.0.5
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	https://security.appspot.com/downloads/
PKGNAMESUFFIX?=	${SSL_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FTP daemon that aims to be "very secure"
WWW=		https://security.appspot.com/vsftpd.html

LICENSE=	GPLv2

USERS=		ftp
GROUPS=		ftp
USES=		cpe alias
ALL_TARGET=	vsftpd
USE_RC_SUBR=	vsftpd vsftpd6
DOCFILES=	AUDIT BENCHMARKS BUGS Changelog FAQ INSTALL LICENSE \
		README README.security README.ssl REFS REWARD \
		SIZE SPEED TODO TUNING

CPE_VENDOR=	vsftpd_project

OPTIONS_DEFINE=	VSFTPD_SSL PIDFILE STACKPROTECTOR DOCS
OPTIONS_DEFAULT?=	VSFTPD_SSL PIDFILE STACKPROTECTOR
NO_OPTIONS_SORT=yes

VSFTPD_SSL_DESC=Include support for SSL
PIDFILE_DESC=	Unofficial support for pidfile
STACKPROTECTOR_DESC=	Build with stack-protector

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVSFTPD_SSL} && !defined(WITHOUT_SSL)
USES+=		ssl
SSL_SUFFIX=	-ssl
CFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-Wno-deprecated-declarations
LDFLAGS+=	-L${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MPIDFILE}
EXTRA_PATCHES+=	${FILESDIR}/pidfile.patch
.endif

VSFTPD_OPTIMIZED=	${CFLAGS:M-O*}
.if defined(CFLAGS) && !empty(VSFTPD_OPTIMIZED)
VSFTPD_NO_OPTIMIZED=	-e "s|-O2 ||"
.endif

.if ${PORT_OPTIONS:MSTACKPROTECTOR}
# BROKEN on FreeBSD with undefined reference to `__stack_chk_fail_local'
VSFTPD_LIBS=	-lssp_nonshared
.else
VSFTPD_NO_SSP=	-e "s|-fstack-protector --param=ssp-buffer-size=4 ||"
.endif

do-configure:
.if ${PORT_OPTIONS:MVSFTPD_SSL} && !defined(WITHOUT_SSL)
	${REINPLACE_CMD} -e \
		"s|#undef VSF_BUILD_TCPWRAPPERS|#define VSF_BUILD_TCPWRAPPERS 1|" \
		-e "s|#undef VSF_BUILD_SSL|#define VSF_BUILD_SSL 1|" \
		${WRKSRC}/builddefs.h
.else
	${REINPLACE_CMD} -e \
		"s|#undef VSF_BUILD_TCPWRAPPERS|#define VSF_BUILD_TCPWRAPPERS 1|" \
		${WRKSRC}/builddefs.h
.endif
	${REINPLACE_CMD} -e "s|^listen=.*|listen=NO|" \
		-e "s|/etc/vsftpd.conf|${PREFIX}/etc/vsftpd.conf|" \
		${WRKSRC}/defs.h ${WRKSRC}/vsftpd.conf
	${REINPLACE_CMD} -e "s|/etc/v|${PREFIX}/etc/v|" \
		${WRKSRC}/vsftpd.8 ${WRKSRC}/vsftpd.conf.5 ${WRKSRC}/tunables.c
	${REINPLACE_CMD} ${VSFTPD_NO_OPTIMIZED} ${VSFTPD_NO_SSP} \
		-e "s|^CC 	=	gcc|CC	=	${CC}|" \
		-e "s|^CFLAGS	=	|CFLAGS	=	${CFLAGS} |" \
		-e "s|^LDFLAGS	=	|LDFLAGS	=	${LDFLAGS} |" \
		-e "s|	-Wl,-s|	${VSFTPD_LIBS}|" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/-lutil/d' ${WRKSRC}/vsf_findlibs.sh
	${CAT} ${FILESDIR}/chroot.conf >> ${WRKSRC}/vsftpd.conf
	${CP} ${WRKSRC}/vsftpd.conf ${WRKSRC}/vsftpd6.conf
.if ${PORT_OPTIONS:MPIDFILE}
	${CAT} ${FILESDIR}/pidfile.conf >> ${WRKSRC}/vsftpd.conf
	${SED} -e 's|vsftpd.pid|vsftpd6.pid|' ${FILESDIR}/pidfile.conf \
		>> ${WRKSRC}/vsftpd6.conf
.endif
	${CAT} ${FILESDIR}/listen.conf >> ${WRKSRC}/vsftpd.conf
	${CAT} ${FILESDIR}/listen6.conf >> ${WRKSRC}/vsftpd6.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${STAGEDIR}${PREFIX}/libexec/
	${LN} ${STAGEDIR}${PREFIX}/libexec/vsftpd ${STAGEDIR}${PREFIX}/libexec/vsftpd6
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${STAGEDIR}${PREFIX}/etc/vsftpd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/vsftpd6.conf ${STAGEDIR}${PREFIX}/etc/vsftpd6.conf.sample
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${MKDIR} ${STAGEDIR}/var/ftp ${STAGEDIR}${PREFIX}/share/vsftpd/empty

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.for i in EXAMPLE SECURITY
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	${CP} -p -R -L ${WRKSRC}/${i}/./ ${STAGEDIR}${DOCSDIR}/${i}/
	${CHMOD} -R -L a+rX,go-w ${STAGEDIR}${DOCSDIR}/${i}/
.endfor

.include <bsd.port.mk>
