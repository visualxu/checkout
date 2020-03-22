#include"createdatabase.h"
QSqlQuery createdata::createbase() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("checkout");
        db.setUserName("root");
        db.setPassword("58271769");
        if (!db.open()) {
            fprintf(stderr,"open database failed !\n");
        }
        QSqlQuery query;
        query.exec("create table list(出厂编号 int primary key,"
                   "委托单位 text,"
                   "地址 text,"
                   "仪器名称 text,"
                   "型号规格 text,"
                   "制造厂家 text,"
                   "生产日期 date,"
                   "准确度级别 text,"
                   "功率因素 float,"
                   "额定容量 text,"
                   "电压范围 text,"
                   "额定电压 text,"
                   "试验电压 int,"
                   "额定频率 int,"
                   "证书编号 text,"
                   "校准依据 text,"
                   "校准地点 text,"
                   "环境温度 int,"
                   "相对湿度 int,"
                   "校准日期 date,"
                   "有效日期 date,"
                   "校验员 text,"
                   "核验员 text,"
                   "外观和通电检查 text,"
                   "绝缘电阻 text,"
                   "有功分量和无功分量 text,"
                   "备注 text)CHARSET=utf8");
//        query.exec("create table list(出厂编号 int primary key,"
//                   "委托单位 text)CHARSET=utf8");
        return query;

}
