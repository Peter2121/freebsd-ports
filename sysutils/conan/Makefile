PORTNAME=	conan
DISTVERSION=	2.12.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C/C++ package manager
WWW=		https://conan.io/ \
		https://github.com/conan-io/conan

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PY_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}bottle>=0.12.8:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.3:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecation>=2.0:devel/py-deprecation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>1.4.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.15:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}node-semver>=0.6.1:devel/py-node-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patch-ng>=1.18.0:devel/py-patch-ng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluginbase>=0.5:devel/py-pluginbase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.4.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.6,1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.28.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
