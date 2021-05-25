/*
================================================================================
                  Random Number Generation and Sampling
================================================================================
*/

#include <random>
#include <functional>
#include <assert.h>

namespace dist {
using namespace std;
using namespace glm;

//Random Number Generator
random_device rd;
mt19937 gen(rd());

//Base Distributions
bernoulli_distribution brn(0.5);
bool bernoulli(){
  return brn(gen);
}

uniform_real_distribution<> unf(0.0, 1.0);
float uniform(){
  return unf(gen);
}

//Inverse Transform Sampling
float inverse(function<float(float)> CDF, float tol = 0.0001f, float approach = 0.05f){
//  assert(CDF(1.0f) == 1.0f);
  float u = uniform();
  float x = 0.5f;
  while(abs(u - CDF(x)) > tol)
    x += approach*(u-CDF(x));
  return x;
}

//Set of Normalized CDFs
float squarebimode(){             //Normalized Quadratic in [0,1]
  return inverse([](float x){
    return 2*x-3*x*x+2*x*x*x;
  });
}

float squaresinglemode(){         //Normalized Negative Quadratic in [0,1]
  return inverse([](float x){
    return 3*x*x-2*x*x*x;
  });
}

float normal(float mean, float std){
  return inverse([&](float x){
    return 0.5*(1+erf((x-mean)/std/sqrt(2)));
  });
}

vec3 normal(vec3 mean, vec3 std){
  vec3 sample = mean;
  sample.x = normal(mean.x, std.x);
  sample.y = normal(mean.y, std.y);
  sample.z = normal(mean.z, std.z);
  return sample;
}


}
