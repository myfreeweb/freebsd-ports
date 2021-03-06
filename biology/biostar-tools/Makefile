PORTNAME=	biostar-tools
PORTVERSION=	0.9.0
CATEGORIES=	biology python

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Meta-port for Biostar Handbook tools

LICENSE=	BSD2CLAUSE

# For a current list see http://data.biostarhandbook.com/install/conda.txt.
# Also included are some programs not listed above, but mentioned in the text.
# sra-tools is almost complete and will be added pending testing
RUN_DEPENDS=	wget>0:ftp/wget \
		curl>0:ftp/curl \
		nano>0:editors/nano \
		parallel>0:sysutils/parallel \
		seqkit>0:biology/seqkit \
		csvtk>0:science/csvtk \
		ncbi-entrez-direct>0:biology/ncbi-entrez-direct \
		readseq>0:biology/readseq \
		snpeff>0:biology/snpeff \
		picard-tools>0:biology/picard-tools \
		bbmap>0:biology/bbmap \
		minimap2>0:biology/minimap2 \
		bwa>=0:biology/bwa \
		bowtie2>=0:biology/bowtie2 \
		samtools>0:biology/samtools \
		emboss>0:biology/emboss \
		bedtools>0:biology/bedtools \
		bamtools>0:biology/bamtools \
		${PYTHON_PKGNAMEPREFIX}cutadapt>0:biology/py-cutadapt@${PY_FLAVOR} \
		seqtk>0:biology/seqtk \
		datamash>0:textproc/datamash \
		bcftools>0:biology/bcftools \
		sra-tools>0:biology/sra-tools \
		subread>0:biology/subread \
		hisat2>0:biology/hisat2 \
		trimmomatic>0:biology/trimmomatic \
		fastqc>0:biology/fastqc \
		picard-tools>0:biology/picard-tools \
		ncbi-blast+>0:biology/ncbi-blast+ \
		cd-hit>0:biology/cd-hit \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		freebayes>0:biology/freebayes \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		bioawk>0:biology/bioawk \
		vt>0:biology/vt \
		${PYTHON_PKGNAMEPREFIX}crossmap>0:biology/py-crossmap@${PY_FLAVOR}

USES=		metaport python

SUB_FILES=	biostar-shell
PLIST_FILES=	bin/biostar-shell

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/biostar-shell ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
