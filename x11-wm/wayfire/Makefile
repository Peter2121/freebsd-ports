PORTNAME=	wayfire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	3D Wayland compositor
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		nlohmann-json>0:devel/nlohmann-json \
		wf-config>=0.9.0<0.10.0:devel/wf-config \
		${LOCALBASE}/include/xf86drmMode.h:graphics/libdrm \
		wayland-protocols>=1.12:graphics/wayland-protocols \
		glm>=0.9.8:math/glm
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libpng.so:graphics/png \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.17.so:x11-toolkits/wlroots017 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:indirect compiler:c++17-lang gl gnome jpeg meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl glesv2
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	WayfireWM:wf-touch:b8b844f:wftouch/subprojects/wf-touch \
		WayfireWM:wf-utils:08553c4:wfutils/subprojects/wf-utils
MESON_ARGS=	-Dtests=disabled \
		-Dwf-touch:tests=disabled \
		-Dwf-utils:default_library=static \
		${NULL}

.if !exists(/usr/include/omp.h)
# LLVM openmp in base doesn't support powerpc, armv6, armv7 yet
MESON_ARGS+=	-Denable_openmp=false
.endif

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.ifdef GH_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${STAGEDIR}${EXAMPLESDIR}

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
