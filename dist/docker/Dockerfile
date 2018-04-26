FROM ubuntu:14.04
MAINTAINER Lucas Ramage <ramage.lucas@openmailbox.org>

ENV SRC_DIR="/opt/ryzomcore" \
	RYHOME="${SRC_DIR}/code" \
	RYZOM_PATH="${RYHOME}/ryzom" \
	PATH="${PATH}:${RYZOM_PATH}/tools/scripts/linux" \
	MAKEOPTS="-j2" \
	WWW_DIR="/srv/www/ryzom"

RUN apt-get update && apt-get install -y \
	apache2 \
	autoconf \
	php5 \
	php5-mysql \
	php5-gd \
	screen \
	php5-mcrypt \
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
	rrdtool \
&& rm -rf /var/lib/apt/lists/* && \
    hg clone -U https://bitbucket.org/ryzom/ryzomcore $SRC_DIR && \
	cd $SRC_DIR && sed -i '$ a\[extensions]\eol =\mq =' .hg/hgrc && \
	hg update && mkdir build && cd build && \
	cmake -DWITH_NEL_TESTS=OFF -DWITH_NEL_SAMPLES=OFF \
		-DWITH_NEL_TOOLS=OFF -DWITH_RYZOM_CLIENT=OFF \
		-DWITH_RYZOM_SERVER=ON -DWITH_RYZOM_TOOLS=OFF -DWITH_NEL=ON \
		-DWITH_SOUND=OFF -DWITH_STATIC=ON -DWITH_DRIVER_OPENGL=OFF \
		-DWITH_DRIVER_OPENAL=OFF -DWITH_3D=OFF -DWITH_GUI=OFF ../code && \
	make && make install && rm -rf "${SRC_DIR}/build" "${SRC_DIR}/.hg" && \
	mkdir -p "${WWW_DIR}" && \
	cp -R /opt/ryzomcore/code/web/public_php "${WWW_DIR}" && \
	cp -R /opt/ryzomcore/code/web/private_php "${WWW_DIR}" && \
	chown -R www-data:www-data "${WWW_DIR}" && chmod -R o-rwx "${WWW_DIR}" && \
	echo "Listen 40916" >> /etc/apache2/ports.conf && php5enmod mcrypt \
&& apt-get remove -y \
	autoconf \
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
	mercurial

COPY files/apache2.conf /etc/apache2/sites-available/000-default.conf

EXPOSE 80 40916
CMD /usr/sbin/apache2ctl -D FOREGROUND
