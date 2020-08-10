#pragma once
#include <QtCore/QString>

namespace config
{
    bool loadStyleSheet(const QString &sheetName, QString &styleSheet);

    QString GetSkinPath(const QString& strFolder, const QString& strSkinName = QString());

#define SET_MODULE_STYLE_BY_PATH(Folder)                                                                        \
	QString strStyleSheet;																					    \
	bool bRetLoadStyle = config::loadStyleSheet(config::GetSkinPath(Folder, objectName() + ".qss"), strStyleSheet);	\
	if(bRetLoadStyle)																							\
	{																											\
		setStyleSheet(strStyleSheet);																			\
	}

#define SET_MODULE_SKIN_FLODER_PATH(Floder) \
	(DSGUI::DSDir::GetCurrentPath() + "/skin/" + DSGUI::GetSkinVersion() + "/" +QString(Floder) + "/")
} // namespace common