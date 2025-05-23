PORTNAME=	qsynth
DISTVERSION=	1.0.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt fluidsynth front-end application
WWW=		https://qsynth.sourceforge.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cmake compiler:c++17-lang pkgconfig qt:6
USE_QT=		base svg tools:build

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		GRADIENT SYSTEM_TRAY XUNIQUE
OPTIONS_DEFAULT=	GRADIENT SYSTEM_TRAY XUNIQUE

GRADIENT_DESC=		Gradient eye-candy
SYSTEM_TRAY_DESC=	System-tray icon support
XUNIQUE_DESC=		X11 unique/single instance

GRADIENT_CMAKE_BOOL=		gradient
SYSTEM_TRAY_CMAKE_BOOL=		CONFIG_SYSTEM_TRAY
XUNIQUE_USES=			xorg
XUNIQUE_USE=			XORG=x11
XUNIQUE_CMAKE_BOOL=		CONFIG_XUNIQUE

BINARY_ALIAS=	git=false

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|oss,alsa,alsa_seq,|jack,sndio,oss,|; \
		s|alsa,jack,oss,dsound,|jack,sndio,oss,|; \
		s|"/MidiDriver", "alsa_seq"|"/MidiDriver", "jack"|; \
		s|m_settings.value("/SoundFontDir").toString();|m_settings.value("/SoundFontDir").toString().isEmpty() ? "${LOCALBASE}/share/sounds/sf2" : m_settings.value("/SoundFontDir").toString();|' \
		${WRKSRC}/src/qsynthOptions.cpp \
		${WRKSRC}/src/man1/qsynth.1 ${WRKSRC}/src/man1/qsynth.fr.1

.include <bsd.port.mk>
