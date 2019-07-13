#include <cstdio>

// 한 뉴런에서 일어나는 오차 역전파 
// 과정을 간단하게 보여주는 코드
class Neuron
{
public:
	double w_, b_, input_, output_;

	Neuron() : w_(2.0), b_(1.0) {}
	Neuron(const double& w_input, const double& b_input) : w_(w_input), b_(b_input) {}

	double getActivation(const double& x)
	{
		// identity function을 activation함수를 사용하기로 함
		return x;
	}

	double feedForward(const double& _input)
	{
		input_ = _input;

		const double sigma = w_ * input_ + b_;
		output_ = getActivation(sigma);
		return output_;
	}

	double getActivationGradient(const double& x)
	{
		return 1.0;
	}

	void feedForwardAndPrint(const double& input)
	{
		printf("%lf %lf \n", input, feedForward(input));
	}

	void propBackward(const double& target)
	{
		const double lr = 0.1;
		const double gard = (output_ - target)  // aE/aW 
			* 1.0 // ay/af f(x) = y 이므로 미분하면 1.0
			* getActivationGradient(output_);  // af/a(sig)  
		// bias와 Error에서 앞 3개 편미분이 동일하므로
		// 편미분 3과정을 grad로 정의

		w_ = w_ - lr * gard * input_;  // a(sig)/aW
		// sigma를 w로 미분
		
		b_ = b_ - lr * gard * 1.0;	   // a(sig)/ab
		// sigma를 b로 미분
	}
};

int main()
{
	Neuron my_neuron(2.0, 1.0);
	my_neuron.feedForwardAndPrint(1.0);
	
	// Error는 MSE를 쓴다고 가정,
	// activation은 y=x라 가정

	for (int r = 1; r < 100; ++r)
	{
		printf("Training %d\n", r);
		my_neuron.feedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		printf("w = %lf, b = %lf\n\n", my_neuron.w_, my_neuron.b_);
	}

	return 0;
}
