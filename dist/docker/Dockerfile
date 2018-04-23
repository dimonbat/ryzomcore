FROM ubuntu:14.04
MAINTAINER Lucas Ramage <ramage.lucas@openmailbox.org>

# Fetch Dependencies
RUN apt-get update && apt-get upgrade -y && \
	apt-get install -y apache2 \
		autoconf \
		php5 \
		php5-mysql \
		php5-gd \
		screen \
		php5-mcrypt \
		mysql-server \
		mysql-client \
		automake \
		bison \
		build-essential \
		cmake \
		libcurl4-openssl-dev \
		libfreetype6-dev \
		libgl1-mesa-dev \
		libjpeg62-dev \
		libluabind-dev \
		libmysqlclient15-dev \
		libogg-dev \
		libopenal-dev \
		libpng12-dev \
		libvorbis-dev \
		libx11-dev \ 
		libxmu-dev \
		libxml2-dev \
		libxrandr-dev \
		libxrender-dev \
		libxxf86vm-dev \
		libcpptest-dev \
		mercurial \
		rrdtool

# Fetch and compile source code
ENV CORE_DIR="/usr/src/ryzomcore" RYHOME="${CORE_DIR}/code" \
	RYZOM_PATH="${RYHOME}/ryzom" PATH="${PATH}:${RYZOM_PATH}/tools/scripts/linux"
RUN hg clone -U https://bitbucket.org/ryzom/ryzomcore $CORE_DIR && \
	cd $CORE_DIR && sed -i '$ a\[extensions]\eol =\mq =' .hg/hgrc && \
	hg update && mkdir build && cd build && \
	cmake -DWITH_NEL_TESTS=OFF -DWITH_NEL_SAMPLES=OFF \
		-DWITH_NEL_TOOLS=OFF -DWITH_RYZOM_CLIENT=OFF \
		-DWITH_RYZOM_SERVER=ON -DWITH_RYZOM_TOOLS=OFF -DWITH_NEL=ON \
		-DWITH_SOUND=OFF -DWITH_STATIC=ON -DWITH_DRIVER_OPENGL=OFF \
		-DWITH_DRIVER_OPENAL=OFF -DWITH_3D=OFF -DWITH_GUI=OFF ../code && \
	make && make install && \
	rm -rf "${CORE_DIR}"

EXPOSE 80 40916
ENTRYPOINT ["/usr/sbin/shardctl", "start"]
