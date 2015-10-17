#pragma once
#include "Interfaces.h"

class lampara: IEnergia, IPredenr, IApagar{

 public:
  Lampara(bool prendida, float nivel);
  ~lampara();
  float obtNivelEnergia();
  bool estaPrendida();
  void consumir(float nivel);
  void cargar(float nivel);
  void prender();
  void apagar();

  float nivel;

 private:
  bool prendido;
}
