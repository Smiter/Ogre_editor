#ifndef IGIZMO_H
#define IGIZMO_H

class IGizmo
{
public:
    virtual void draw(bool,bool,bool,bool=false)=0;
    virtual void show()=0;
    virtual void hide()=0;
    virtual void scale(float,float,float)=0;
    virtual Ogre::Vector3 getScale()=0;
    virtual void setPosition(Ogre::Vector3)=0;
    virtual void setBoundSize(float size)
    {
        boundsize = size;
    }

    bool isVisible;
    float boundsize;
};

#endif // IGIZMO_H
