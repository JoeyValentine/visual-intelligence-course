#include <cstdio>

// �� �������� �Ͼ�� ���� ������ 
// ������ �����ϰ� �����ִ� �ڵ�
class Neuron
{
public:
	double w_, b_, input_, output_;

	Neuron() : w_(2.0), b_(1.0) {}
	Neuron(const double& w_input, const double& b_input) : w_(w_input), b_(b_input) {}

	double getActivation(const double& x)
	{
		// identity function�� activation�Լ��� ����ϱ�� ��
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
			* 1.0 // ay/af f(x) = y �̹Ƿ� �̺��ϸ� 1.0
			* getActivationGradient(output_);  // af/a(sig)  
		// bias�� Error���� �� 3�� ��̺��� �����ϹǷ�
		// ��̺� 3������ grad�� ����

		w_ = w_ - lr * gard * input_;  // a(sig)/aW
		// sigma�� w�� �̺�
		
		b_ = b_ - lr * gard * 1.0;	   // a(sig)/ab
		// sigma�� b�� �̺�
	}
};

int main()
{
	Neuron my_neuron(2.0, 1.0);
	my_neuron.feedForwardAndPrint(1.0);
	
	// Error�� MSE�� ���ٰ� ����,
	// activation�� y=x�� ����

	for (int r = 1; r < 100; ++r)
	{
		printf("Training %d\n", r);
		my_neuron.feedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		printf("w = %lf, b = %lf\n\n", my_neuron.w_, my_neuron.b_);
	}

	return 0;
}
