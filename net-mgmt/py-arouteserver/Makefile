PORTNAME=	arouteserver
PORTVERSION=	1.15.1
PORTREVISION=	2
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool to automatically build configurations for BGP route servers
WWW=		https://github.com/pierky/arouteserver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aggregate6>=1.0.12:net-mgmt/py-aggregate6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9.4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.13:devel/py-pyyaml@${PY_FLAVOR} \
		bash>0:shells/bash \
		bgpq4>0:net-mgmt/bgpq4 \
		ca_root_nss>0:security/ca_root_nss
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.7:devel/py-nose@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	pierky/arouteserver/config.d/rtt_getter.sh
NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${SETENV} nosetests -vs --tests=tests/external_resources/)

.include <bsd.port.mk>
