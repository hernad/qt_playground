#include "plug_app.h"


int main(int argc , char* argv[])
{
	QApplication app(argc,argv);
	
	QDir dir (QApplication::applicationDirPath());

	qDebug() << dir.absolutePath();

    QStringList paths = QCoreApplication::libraryPaths();
    for (QStringList::iterator it = paths.begin(); it!=paths.end(); it++)
	{
		      qDebug()	 << "Looking for plugins at path: " << *it;
	}


/*
     pluginsDir = QDir(qApp->applicationDirPath());

 #if defined(Q_OS_WIN)
     if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
         pluginsDir.cdUp();
 #elif defined(Q_OS_MAC)
     if (pluginsDir.dirName() == "MacOS") {
         pluginsDir.cdUp();
         pluginsDir.cdUp();
         pluginsDir.cdUp();
     }
 #endif
     pluginsDir.cd("plugins");

     foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
         QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
         QObject *plugin = loader.instance();
         if (plugin) {
             populateMenus(plugin);
             pluginFileNames += fileName;
         }
     }
*/


	QPluginLoader loader(dir.absoluteFilePath("libplugin_1.dylib"));

	QObject *plugin = loader.instance();

     Plugin1 *i_plugin_1 = qobject_cast<Plugin1 *>(plugin);
     if (i_plugin_1)
		 i_plugin_1->start(&app);
	 else
		 qDebug() << "i_plugin_1 je null ?!?!";


	return 0;
}
