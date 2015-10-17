#pragma once

class Difusor{

 private:
  float anguloDifusion;

 public:
  Difusor();
  Difusor(float anguloDifusion);
  float obtAnguloDifusion();
  virtual bool potenciaDifusion(float potencia);
  void estAnguloDifusion(float anguloDifusion);
  virtual ~Difusor();
  
};

class DifusorCentral : public Difusor{
  
 private:
  float difusorCentral;

 public:
  DifusorCentral();
  DifusorCentral(float difusorCentral, float anguloDifusion);
  void establecerDifusorCentral(float difusorCentral);
  bool potenciaDifusor(float potencia);
  ~DifusorCentral();

};

class DifusorBivalente : public Difusor{

 private:
  float anguloPost;

 public:
  DifusorBivalente();
  DifusorBivalente(float anguloPost, float anguloDifusion);  
  void estAnguloPost(float anguloPost);
  float obtAnguloPost();  
  ~DifusorBivalente();
  
};

class DifusorBivalenteCentral : public DifusorBivalente{

 private:
  float difusorBic;

 public:
  DifusorBivalenteCentral();
  DifusorBivalenteCentral(float difusorBic, float anguloPost, float anguloDifusion);
  void establecerDifusorBic(float difusorBic);
  virtual bool potenciaDifusion(float potencia);
  ~DifusorBivalenteCentral();

};
