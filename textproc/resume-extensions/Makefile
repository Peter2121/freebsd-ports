PORTNAME=	resume-extensions
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://aaronland.info/xsl/xmlresume/
DISTNAME=	xml${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extends the XML Resume library
WWW=		https://aaronland.info/xsl/xmlresume/

DEPRECATED=	Depends on deprecated port textproc/resume
EXPIRATION_DATE=2025-04-30

RUN_DEPENDS=	resume>0:textproc/resume \
		${LOCALBASE}/share/xsl/string/print-n-times.xsl:textproc/print-n-times \
		${LOCALBASE}/share/xsl/xhtml/add-css-links.xsl:textproc/add-css-links

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/share|${LOCALBASE}/share|' \
		${WRKSRC}/lib/extrefs.xsl
	${REINPLACE_CMD} -e 's|/usr/local/share|${LOCALBASE}/share|' \
		${WRKSRC}/format/html.xsl
	${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${ECHO} "Installing in ${PREFIX}/share/xsl/${PORTNAME}"
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}

.include <bsd.port.mk>
