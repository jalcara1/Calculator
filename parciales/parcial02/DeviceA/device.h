#pragma Once

class Device{

 private:
  int factorOne;
 public:
  Device();
  Device(int factorOne);
  virtual int compute() =0;
  int getFactorOne();
  virtual ~Device();
};


class DevByTen : public Device{
 private:

 public:
  DevByTen();
  DevByTen(int factorOne);
  int compute();
  ~DevByTen();
};

class DevByFive : public Device{

 private:

 public:
  DevByFive();
  DevByFive(int factorOne);
  int compute();
  ~DevByFive();
};

class Device2 : public Device{

 private:
  int factorTwo;

 public:
  Device2();
  Device2(int factorTwo, int factorOne);
  int getFactorTwo();
  ~Device2();
};


class Dev2MinusFive : public Device2{

 private:

 public:
  Dev2MinusFive();
  Dev2MinusFive(int factorTwo);
  int compute();
  ~Dev2MinusFive();  
};

class Dev2AddTen : public Device2{

 private:

 public:
  Dev2AddTen();
  Dev2AddTen(int factorTwo);
  int compute();
  ~Dev2AddTen();
};
