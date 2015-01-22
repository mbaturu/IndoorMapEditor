#include "jsonloader.h"
#include "../core/mapentity.h"
#include "../core/building.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>


JsonLoader::JsonLoader(){
}

MapEntity* JsonLoader::loadFile(const QString & fileName) {
       QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly)) {
           qWarning("Couldn't open the file.");
           return NULL;
       }

       QByteArray jsonData = file.readAll();
       QJsonDocument loadDoc(QJsonDocument::fromJson(jsonData));

       Building * building = new Building("");
       if(building->load(loadDoc.object())){
           return building;
       }else{
           delete building;
           building = NULL;
       }
       return building;
}

bool JsonLoader::saveFile(const QString &fileName, const MapEntity *mapEntity, double scale) {

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open the file.");
        return false;
    }

    QJsonObject jsonObject;
    mapEntity->save(jsonObject, scale);
    QJsonDocument saveDoc(jsonObject);
    file.write(saveDoc.toJson());
    return true;
}
