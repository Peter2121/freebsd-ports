PORTNAME=	kopete
PORTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multi-protocol instant messenger
WWW=		https://apps.kde.org/kopete/

IGNORE=		does not build with KF6
DEPRECATED=	Unmaintained and no longer released by the KDE community
EXPIRATION_DATE=	2025-03-31

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libidn.so:dns/libidn \
		libjasper.so:graphics/jasper \
		libotr.so:security/libotr \
		libv4l2.so:multimedia/libv4l

USES=		cmake compiler:c++11-lang desktop-file-utils gnome jpeg kde:5 \
		qca qt:5 shebangfix tar:xz xorg
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons dnssd emoticons guiaddons i18n \
		iconthemes itemviews jobwidgets js kcmutils kdelibs4support \
		khtml kio notifications notifyconfig parts phonon service solid sonnet \
		syntaxhighlighting texteditor textwidgets unitconversion wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
# KDE PIM components
USE_KDE+=	contacts identitymanagement libkleo pimtextedit
USE_QT=		concurrent core dbus gui network printsupport sql widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

SHEBANG_FILES=	protocols/winpopup/winpopup-install \
		protocols/winpopup/winpopup-send \
		kopete/kconf_update/*.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
