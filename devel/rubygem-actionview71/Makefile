PORTNAME=	actionview
PORTVERSION=	7.1.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, battle-tested conventions and helpers for building web pages
WWW=		https://github.com/rails/rails/tree/main/actionview \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-builder>=3.1<4:devel/rubygem-builder \
		rubygem-erubi>=1.11<2:www/rubygem-erubi \
		rubygem-rails-dom-testing-rails71>=2.2<3:textproc/rubygem-rails-dom-testing-rails71 \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
