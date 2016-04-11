#include "skybox.h"

//--------------------------------------------------------------------------------------------
// domyslny konstruktor 
glSkyBox::glSkyBox(float R, float H,char *TextureFile)
{
	tex = NULL;
	tex = new glTexture(TextureFile);

	// przygotuj geometrie obiektu 
	float kat = 0.0; 
	int slices = 50; 
	float dk = 360.0/float(slices-1); 
	float du = 1.0f / float(slices - 1);

	float u = 0.0f;
	BeginObject(GL_TRIANGLE_STRIP, tex->Bind());	
		
	SetColor(1.0,1.0,1.0);
	
	while (kat <= 360.0)
	{
		AddVertex(R*cos(kat*PI/180.0),H/2.0,R*sin(kat*PI/180.0),u, 1.0f);
		AddVertex(R*cos(kat*PI/180.0),-H/2.0,R*sin(kat*PI/180.0), u);
		u += du;
		kat += dk;		
	}
	
	EndObject();
}
//--------------------------------------------------------------------------------------------
// domyslny destruktor 
glSkyBox::~glSkyBox()
{	
	if (tex) delete tex;
}
//--------------------------------------------------------------------------------------------
// the end 
