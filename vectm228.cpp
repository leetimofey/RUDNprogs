#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

class vect {
	int dim;
	double *v;
	
	public:
    	friend class matrix;
    		vect& operator = (const vect &r);//������������
			vect operator + (const vect &r);//��������
			double operator * (const vect &r);//������*������
			const bool operator ==(const vect &r);//���������
			const bool operator !=(const vect &r);//������ ���������
			vect operator += (const vect &r);//��������
			vect operator -= (const vect &r);//���������
			vect operator - ();//������� �����
			vect operator - (const vect &r);//���������
			double operator [] (int i);//����������
			friend vect operator * (const vect &l, double k);//������*�����
			
			static int count;
			int num;
			
			vect (int d, double *x);//�����������
			vect (int d);//�����������
			vect (vect& b);//�����������
			vect ();//�����������
			
			~vect();//����������
			
			void set(double x[], int d);//����� �������
			void print();//����� �� �����
			void setCoordinate(double newOne, int k);//����� ���������
			
			int getn();//�����������
			double getCoordinate(int k);//����������
};

class matrix{
	int dim;
	double **v;
	
public:
    //������������
    matrix(int d, double **x);
    matrix(int d);
    matrix(const matrix& a);
    matrix();

    ~matrix(); //����������

    static int count;
    int num;

    void print();
    void set (int dim, double **x);

    const bool operator == (const matrix &r);//���������
    const bool operator != (const matrix &r);//���������
    matrix& operator = (const matrix &r);//������������
    matrix operator - ();//������� �����
    matrix operator - (const matrix &r);//���������
    matrix operator + (const matrix &r);//��������
    matrix operator * (const matrix &r);//���������
    matrix multiply (double k);//�������*�����

    vect operator * (const vect &r);//�������*������
    void transparent();
    void obrDiag();//�������� ���������
    double getCoordinate (int n, int m);//��������� ���������
};


		
vect& vect::operator =(const vect&r) {
    if (dim!=r.dim){
        dim=r.dim;
        delete [] v;
        v=new double[dim];
    }
	else{
    	for (int i=0; i<dim; i++)
			v[i]=r.v[i];
	}

	return *this;
}
    vect vect :: operator + (const vect &r) {
    if (dim!=r.dim) exit(1);

    vect tmp(dim);

    for (int i=0; i<dim; i++) {
        tmp.v[i]=v[i]+r.v[i];
    }

    return tmp;
}
			
vect vect :: operator - (const vect &r) {
    if (dim!=r.dim) exit(1);

    vect tmp(dim);

    for (int i=0; i<dim; i++) {
        tmp.v[i]=v[i]-r.v[i];
    }

    return tmp;
};
			
double vect::operator*(const vect &r) {
    double s=0;
    double p;

    for (int i=0; i<dim; i++) {
        p=v[i]*r.v[i];
        s=s+p;
        p=0;
    }

    return s;
}

vect operator * (const vect &l, double k) {
    int d=l.dim;
    vect tmp(d);

    for (int i=0; i<d; i++) {
        tmp.v[i]=l.v[i]*k;
    }

    return tmp;
}

const bool vect::operator==(const vect &r) {
    if (dim!=r.dim) exit(1);

    bool znak=true;

    for (int i=0; i<dim; i++) {
        if (v[i]!=r.v[i]) znak=false;
    }

    return znak;
}

const bool vect :: operator !=(const vect &r) {
    if (dim!=r.dim) exit (1);

    bool znak=true;

    for (int i=0; i<dim; i++) {
        if (v[i]==r.v[i]) znak=false;
    }

    return znak;
}

vect vect::operator += (const vect &r) {
    if (dim!=r.dim) exit (1);

    vect tmp(dim,v);

    for (int i=0; i<dim; i++) {
        tmp.v[i]=tmp.v[i]+r.v[i];
    }

    return tmp;
}
			
			
vect vect::operator -= (const vect &r) {
    if (dim!=r.dim) exit (1);

    vect tmp(dim,v);

    for (int i=0; i<dim; i++) {
        tmp.v[i]=tmp.v[i]-r.v[i];
    }

    return tmp;
}

vect vect::operator - () {
    vect tmp(dim,v);

    for (int i=0; i<dim; i++)
        tmp.v[i]=tmp.v[i]*(-1);

    return tmp;
}

double vect::operator [] (int i) {
    if (i<1 || i>dim) {
        cout<<"Error: ������������ ������"; exit(1);
    }

    return v[i-1];
};
			

void vect::print() {
    if (dim!=0){
	    cout << "(";
	    for (int i = 0; i < dim-1; i++)
            cout << v[i] << "; ";
	    cout << v[dim-1] << ")" << endl;
    } else cout << ")" << endl;
};



void vect::setCoordinate(double newOne, int k)
{ v[k-1]=newOne; }

void vect :: set(double x[], int dim)
{
for (int i=0; i<dim; i++)
 {v[i]=x[i];};
}



int vect::getn() {
    return dim;
}

double vect :: getCoordinate(int k) {
    return v[k];
};


vect::vect(int d) {
    count ++;
	num=count;
	dim=d;
	v=new double[dim];

	for (int i=0; i<dim; i++) {
		v[i] = 0;
	}
}
	
vect::vect(int d, double *x) {
    count ++;
    num=count;
    dim=d;
    v=new double[dim];

    for (int i=0; i<dim; i++) {
        v[i]=x[i];
    }
};

vect::vect(vect& b) {
    count ++;
	num=count;
	dim=b.dim;
	v=new double[dim];

	for (int i=0; i<dim; i++) {
	    v[i]=b.v[i];
	}
}

vect::vect() {
    count++;
	num = count;
	dim = 0;
	v = new double[0]; // v = NULL
}

vect::~vect() {
	count--; 
	delete [] v;
}

/*vect solveSLU (vect x, vect B, matrix A, matrix I){
	
}*/


void matrix::obrDiag(){
	for(int i=0; i< dim; i++) {
		for (int j=0; j<dim; j++) {
			if(i==j && v[i][j]!=0) {
				v[i][j]=1.0/v[i][j];
			} else {
				v[i][j]=0;
			}
		}
	}
}

vect matrix::operator*(const vect &r) {
	vect res (r.dim);
	
	for (int i = 0; i < dim; i++) {
		for (int k = 0; k < dim; k++) {
			res.v[i]=v[i][k]*r.v[k] + res.v[i];
		}
	}

	return res;
}

const bool matrix::operator ==(const matrix &r){
	bool check = true;
	
	for (int i = 0; i < dim; i++){
	    for (int j = 0; j < dim; j++){
	        if(v[i][j] != r.v[i][j]){
	            check = false;
	        }
	    }

	    if(!check) break;
	}

	return check;
}

double matrix::getCoordinate(int n, int m){
	return v[n][m];
}

const bool matrix::operator != (const matrix &r){
	bool check = false;

	for (int i = 0; i < dim; i++){
	    for (int j = 0; j < dim; j++){
	        if(v[i][j] != r.v[i][j]){
	            check = true;
	        }
		}

	    if(check) break;
	}
	
	return check;
}


void matrix::transparent(){
	matrix clone(dim, v);
	
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
		    clone.v[i][j]=v[j][i];
		}
	}
}


matrix matrix::operator - (){
	matrix tmp(dim,v);
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			 tmp.v[i][j]=v[i][j]*(-1);
		}
	}

	return tmp;
}


matrix matrix::multiply(double k){
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
		    v[i][j]=v[i][j]*k;
		}
	}

	return *this;
}

matrix& matrix::operator = (const matrix &r){
    if (v != NULL) {
        for (int i = 0; i < dim; i++) {
            delete [] v[i];
        }
    	delete [] v;
    }
	this->dim=r.dim;
    v = new double*[dim];
	for(int i=0;i<r.dim;i++){
	    v[i] = new double[dim];
		for(int j=0;j<r.dim;j++){
			this->v[i][j]=r.v[i][j];
		}
	}
	return *this;
}

matrix matrix::operator - (const matrix &r){
	matrix res(r.dim, r.v);

	for (int i = 0; i < res.dim; i++){
		for (int j = 0; j < res.dim; j++){
		    res.v[i][j]=v[i][j]-r.v[i][j];
		}
	}

	return res;
}

matrix matrix::operator + (const matrix &r){
	matrix tmp(r.dim, r.v);
	for(int i=0; i<r.dim; i++){
		for(int j=0; j<r.dim; j++){
			tmp.v[i][j]=r.v[i][j]+v[i][j];
		}
	}
	return tmp;	
}

void matrix::set(int dim, double **x){
	this->dim=dim;
	for(int i=0;i<dim;i++){
		for(int j=0; j<dim;j++){
			v[i][j]=x[i][j];
		}
	}
}

int vect::count=0;

int matrix::count=0;


matrix::matrix() {
    count++;
	num = count;
	dim = 0;
	//v = new double*[0];
	v = NULL;
}

matrix::matrix (int d, double **x) {
    count ++;
    num=count;
    dim=d;
    v=new double*[d];
    for (int i =0 ; i < d; i++) {
        v[i] = new double[d];
        for (int j = 0; j < d; j++) {
            v[i][j] = x[i][j];
        }
    }
}

matrix::matrix (const matrix& a){
    count++;
	num=count;
	dim=a.dim;
	v=new double*[dim];
	for(int i=0; i<dim; i++){
		v[i]=new double[dim];
		for (int j = 0; j < dim; j++) {
		    v[i][j] = a.v[i][j];
		}
	}
}

matrix::matrix (int d){
	count++;
	num = count;
	dim = d;
	v = new double* [d];
	for(int i=0; i<dim; i++){
		v[i] = new double[dim];
		for(int j=0; j<dim; j++){
			v[i][j]=0;
		}
	}
}

matrix::~matrix (){
	//count--;
	if (v != NULL) {
        for (int i = 0; i < dim; i++) {
            delete [] v[i];
        }
		delete [] v;
    }
}

void matrix::print(){
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			cout<<v[i][j]<<" ";
			if (j==(dim-1)){
				cout<<endl;
			}
		}
	}
}


int main() {
	    
		setlocale(LC_ALL,"Russian");
	    srand(time(NULL));
	    
		int n = 3;
	    cout << "������� �����������: ";
	    cin >> n;
	    cout << endl;
	    
	    double **im = new double*[n];
	    
	    for(int i=0; i<n; i++){
	    	im[i] = new double [n];
	    	for(int j=0; j<n; j++){
	    		if(i == j) im[i][j] = 1;
	    		else im[i][j] = 0;
			}
		}
		
		matrix I(n,im);
		cout << "��������� �������: \n\n";
		I.print();

		double **ab = new double *[n];
		cout << endl;
		
		for(int i = 0; i < n; i++){
	    	ab[i]=new double [n];
	    	for(int j = 0; j < n; j++){
	    		ab[i][j] = rand()%100;
			}
		}
		
		matrix A(n, ab);
		cout << "������� A: \n\n";
		A.print();

		double *bb = new double [n];
		for(int i = 0; i < n; i++){
	    	bb[i] = rand()%10;
			}
		cout<<endl;
		
		double k;
		cout << "������� �����: ";
		cin >> k;
		cout << endl;
		
		vect B(n, bb);
		vect C(0);
		vect D(0);
		
		B.print();
		
		B.setCoordinate(69, 2);
		
		cout << "�������� ������ ���������� ������� B: \n" << endl;
		B.print();
		cout << endl;
		
		C = B * k;
		cout << "��������� ������� �� �����: \n";
		C.print();
		cout << endl;
		
		double vect_mult;
		vect_mult = B*B;
		cout << "��������� ������� �� ������: \n" << vect_mult << endl;
		
		D = -C;
		cout << "\n������� ����� � �������� C: \n";
		D.print();
		cout << endl;	
		
		D = A*B;
		cout << "��������� ������� �� ������: \n";
		D.print();
		cout << endl;
		
		if(C == B)
			cout << "������� D � B �����\n" << endl;
		else
		    cout << "������� D � � �� �����\n" << endl;
			
	    if (C != B)
		    cout << "������� D � � �� �����\n" << endl;
		else 
		    cout << "������� D � � �����\n" << endl;	
		
		D = B + C;
		cout << "�������� ��������: \n";
		D.print();
		cout << endl;
		
		D = C - B;
		cout << "��������� ��������: \n";
		D.print();
		cout << endl;

		matrix F(A);

		F.multiply(k);
		cout << "��������� ������� �� �����: " << endl;
		F.print();
		cout << endl;
		
		matrix H(A);
		
		matrix E(n);
		 
		H.obrDiag();
		cout << "�������� ���������: " << endl;
		H.print();
		cout << endl;

	    E = F - A;
	    cout << "�������� ������: " << endl;
	    E.print();
	    cout << endl; 
	    E = A + F;
	    cout << "�������� ������: " << endl;
	    E.print();
	    cout << endl;
		
	
		//printSLU(A,B);
		
		vect x(n);
		
		
		//x=solveSLU(x, B, A, I);

		cout<<endl<<"Answer: ";
		
		x.print();
	
		return 0;
}
