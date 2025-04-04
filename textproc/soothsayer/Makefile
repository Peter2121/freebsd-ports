PORTNAME=	soothsayer
PORTVERSION=	0.6.3
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/presage/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intelligent predictive text entry platform
WWW=		http://presage.sourceforge.net/

LICENSE=	GPLv2+

DEPRECATED=	Deprecated upstream, consider using deskutils/presage
EXPIRATION_DATE=2025-04-30

BUILD_DEPENDS=	help2man:misc/help2man

USES=		compiler libtool localbase ncurses pkgconfig sqlite
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_path_CPPUNIT_CONFIG=no \
		ac_cv_path_PYTHON=no \
		ac_cv_path_SWIG=no \
		ac_cv_prog_HAVE_DOT=no \
		ac_cv_prog_HAVE_DOXYGEN=no
CONFIGURE_ARGS=	--disable-python-binding --localstatedir="${PREFIX}/var"
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}| ; \
		 s|lib/soothsayer|soothsayer|g' ${WRKSRC}/resources/Makefile.in
	@${REINPLACE_CMD} -e 's|lib/soothsayer|soothsayer|' \
		${WRKSRC}/resources/profiles/Makefile.in
	@${REINPLACE_CMD} -e 's@lcurses@lncurses@g' \
		${WRKSRC}/src/tools/Makefile.in
	@${REINPLACE_CMD} -E -e "s|(LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		-e "s|(.*SQLITE_LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		-e 's@lcurses@lncurses@g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
