#pragma once

class IApagar{
 public:
  void apagar();
};

class IEnergia{
 public:
  void consumir(float nivel);
  void cargar(float nivel);
};
class IPrender{
 public:
  void prender();
};
