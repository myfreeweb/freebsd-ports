PORTNAME=	libArcus
PORTVERSION=	4.9.0
PORTEPOCH=	1
CATEGORIES=	net cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Communication library between internal components for Ultimaker

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lang python:3.5+ pyqt:5
USE_PYQT=	sip pysip
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD} \
				-DPYTHON_INCLUDEDIR:STRING=${PYTHON_INCLUDEDIR}
.include <bsd.port.mk>
