PORTNAME=	icu-utils
DISTVERSION=	0.0-20220329
PORTREVISION=	5
CATEGORIES=	textproc
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Lua interface to selected ICU utilities
WWW=		https://github.com/adam-stanek/lua_icu_utils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		gmake lua:module

USE_GITHUB=	yes
GH_ACCOUNT=	adam-stanek
GH_PROJECT=	lua_icu_utils
GH_TAGNAME=	431dda1de

CFLAGS+=	-fPIC -I${LOCALBASE}/include
LDFLAGS+=	-shared -L${LOCALBASE}/lib
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LUA_INCDIR="${LUA_INCDIR}"

PLIST_FILES=	${LUA_MODLIBDIR}/icu_utils.so
PORTDOCS=	README.md

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/icu_utils.so ${STAGEDIR}${LUA_MODLIBDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
