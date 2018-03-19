# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	gajim
PORTVERSION=	1.0.0
CATEGORIES=	net-im
MASTER_SITES=	https://gajim.org/downloads/1.0/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Jabber client based on a plugin system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbxmpp>=0.6.4:net-im/py-nbxmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>0:security/py-python-gnupg@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python:3.4+ tar:bzip2
USE_PYTHON=	autoplist distutils
USE_GNOME=	intltool gtk30 cairo pygobject3

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	AVAHI CRYPTO DBUS DOCS GUPNP NLS SPELL
OPTIONS_DEFAULT=DBUS SPELL
OPTIONS_SUB=	yes

CRYPTO_DESC=	End to end encryption support
GUPNP_DESC=	UPnP IGD protocol support
SPELL_DESC=	Spell checking support

AVAHI_RUN_DEPENDS=	avahi-discover:net/py-avahi@${PY_FLAVOR}
CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:devel/py-dbus@${PY_FLAVOR}
GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:net/gupnp-igd
NLS_USES=		gettext
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

SUB_FILES=	pkg-message

.include <bsd.port.mk>
