#include "fenetresite.h"
#include <QString>

FenetreSite::FenetreSite(QObject *parent) : QObject(parent)
{
    m_site = new Site;

    m_site->ajouter(new Borne("Le calvaire symbole monfortain","St Laurent sur sevre","calvaire","",1));
    m_site->ajouter(new Borne("Chapelle de la Sagesse","St Laurent sur sevre","chapelle","",2));
    m_site->ajouter(new Borne("Maison longue","St Laurent sur sevre","maison","",3));
    m_site->ajouter(new Borne("Pont Eiffel","St Laurent sur sevre","maison","",4));

    m_liste = m_site->getNames();
}

void FenetreSite::start()
{
    m_engine.rootContext()->setContextProperty("fenetreSite",this);
    m_engine.rootContext()->setContextProperty("site",QVariant::fromValue(this->m_liste));
    qDebug(QString::number(m_liste.size()).toStdString().c_str() );
    m_engine.load(QUrl(QStringLiteral("qrc:/fenetreSite.qml")));
}

FenetreSite::~FenetreSite()
{

}

QStringList FenetreSite::site()
{
    return m_liste;
}

void FenetreSite::setSite( QStringList site)
{
    m_liste = site;
}