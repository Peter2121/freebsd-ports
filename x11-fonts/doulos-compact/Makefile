PORTNAME=	DoulosSILCompact
DISTVERSION=	6.200
CATEGORIES=	x11-fonts
# Use the port maintainer's GitHub to fetch the font, since the SIL server
# embeds dynamic content into the file.
MASTER_SITES=	https://raw.githubusercontent.com/zoliky/distfiles/refs/heads/main/

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	Doulos SIL TrueType font collection, compact variant
WWW=		https://software.sil.org/doulos/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	${FONTSDIR}/${PORTNAME}-Regular.ttf

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt README.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
