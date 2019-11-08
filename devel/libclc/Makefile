# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	libclc
DISTVERSION=	11.0.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION:S/rc/-rc/}/
DISTNAME=	llvm-project-${DISTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language

LICENSE=	LLVM2
LICENSE_FILE=	${WRKSRC}/libclc/LICENSE.TXT
LICENSE_NAME=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>=4.0:devel/llvm${LLVM_DEFAULT} \
		libedit>=0:devel/libedit

USES=		cmake compiler:c++11-lib python:3.6+,build tar:xz
USE_LDCONFIG=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_SOURCE_PATH=	${WRKSRC}/libclc
CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}

.include <bsd.port.mk>
