PORTNAME=	weka
DISTVERSION=	3-8-6
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-3-8/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data Mining Software in Java
WWW=		https://www.cs.waikato.ac.nz/ml/weka/

LICENSE=	GPLv2

PORTSCOUT=	limitw:1,even	# Second component is even for stable versions.

USES=		java zip

NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${PORTNAME}.jar

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar \
		${STAGEDIR}${DATADIR}/${PORTNAME}.jar
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
