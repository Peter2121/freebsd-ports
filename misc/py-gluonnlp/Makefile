PORTNAME=	gluonnlp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	3
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MXNet-based toolkit to enable easy text, datasets preprocessing
WWW=		https://gluon-nlp.mxnet.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expiring misc/py-mxnet
EXPIRATION_DATE=2025-06-01

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mxnet>0:misc/py-mxnet@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python localbase
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_PROJECT=	gluon-nlp
USE_PYTHON=	distutils cython autoplist

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
