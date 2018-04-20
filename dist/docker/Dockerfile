FROM ubuntu:14.04
MAINTAINER Lucas Ramage <ramage.lucas@openmailbox.org>

# Fetch Dependencies
RUN apt-get update && apt-get upgrade -y && \
	apt-get install -y autoconf \
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
	cp $RYHOME/build/bin/ryzom_admin_service $RYZOM_PATH/server/src/ryzom_admin_service/ryzom_admin_service && \
	cp $RYHOME/build/bin/ryzom_ai_service $RYZOM_PATH/server/src/ai_service/ai_service &&\ 
	cp $RYHOME/build/bin/ryzom_backup_service $RYZOM_PATH/server/src/backup_service/backup_service && \
	cp $RYHOME/build/bin/ryzom_dynamic_scenario_service $RYZOM_PATH/server/src/dynamic_scenario_service/dynamic_scenario_service && \
	cp $RYHOME/build/bin/ryzom_entities_game_service $RYZOM_PATH/server/src/entities_game_service/entities_game_service && \
	cp $RYHOME/build/bin/ryzom_frontend_service $RYZOM_PATH/server/src/frontend_service/frontend_service && \
	cp $RYHOME/build/bin/ryzom_gpm_service $RYZOM_PATH/server/src/gpm_service/gpm_service && \
	cp $RYHOME/build/bin/ryzom_ios_service $RYZOM_PATH/server/src/input_output_service/input_output_service && \
	cp $RYHOME/build/bin/ryzom_log_analyser_service $RYZOM_PATH/server/src/log_analyser_service/log_analyser_service && \
	cp $RYHOME/build/bin/ryzom_logger_service $RYZOM_PATH/server/src/logger_service/logger_service && \
	cp $RYHOME/build/bin/ryzom_mail_forum_service $RYZOM_PATH/server/src/mail_forum_service/mail_forum_service && \
	cp $RYHOME/build/bin/ryzom_mirror_service $RYZOM_PATH/server/src/mirror_service/mirror_service && \
	cp $RYHOME/build/bin/ryzom_naming_service $RYZOM_PATH/server/src/ryzom_naming_service/ryzom_naming_service && \
	cp $RYHOME/build/bin/ryzom_pd_support_service $RYZOM_PATH/server/src/pd_support_service/pd_support_service && \
	cp $RYHOME/build/bin/ryzom_persistant_data_service $RYZOM_PATH/server/src/persistant_data_service/persistant_data_service && \
	cp $RYHOME/build/bin/ryzom_reference_builder_service $RYZOM_PATH/server/src/pd_reference_builder/pd_reference_builder && \
	cp $RYHOME/build/bin/ryzom_session_browser_service $RYZOM_PATH/server/src/session_browser_server/session_browser_server && \
	cp $RYHOME/build/bin/ryzom_shard_unifier_service $RYZOM_PATH/server/src/shard_unifier_service/shard_unifier_service && \
	cp $RYHOME/build/bin/ryzom_tick_service $RYZOM_PATH/server/src/tick_service/tick_service && \
	cp $RYHOME/build/bin/ryzom_welcome_service $RYZOM_PATH/server/src/ryzom_welcome_service/ryzom_welcome_service && \
	sed -i 's:/bin/sh:/bin/bash:g' $RYZOM_PATH/tools/scripts/linux/shard && \
	sed -i 's:/bin/sh:/bin/bash:g' $RYZOM_PATH/server/shard.screen.rc
