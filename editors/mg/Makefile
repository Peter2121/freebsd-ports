PORTNAME=	mg
DISTVERSION=	20241008
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	https://hydrus.org.uk/downloads/

MAINTAINER=	cdr.nil@gmail.com
COMMENT=	Small, fast Emacs-like editor
WWW=		https://man.openbsd.org/mg

LICENSE=	PD

FLAVORS=		dynamic static
FLAVOR?=		${FLAVORS:[1]}
static_PKGNAMESUFFIX=	-static

USES=		ncurses uidfix

.if ${FLAVOR} == static
COMMENT+=	(rescue(8) version)
MAKE_ARGS+=	NO_SHARED=yes
PLIST_FILES=	/rescue/mg
.else
PLIST_FILES=	bin/mg \
		share/man/man1/mg.1.gz
PORTDOCS=	README tutorial
OPTIONS_DEFINE=	DOCS
.endif

MAKE_ARGS+=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/share/man/man \
		NCURSESINC=${NCURSESINC} \
		NCURSESLIB=${NCURSESLIB}

.if ${FLAVOR} == static
do-install:
	@${MKDIR} ${STAGEDIR}/rescue
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${STAGEDIR}/rescue
.else
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
