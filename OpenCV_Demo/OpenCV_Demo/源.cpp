#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2\opencv.hpp>
using namespace cv;
using namespace std;
std::vector<Rect> faces;
Mat img_gray;
int x = 0;
CascadeClassifier face_cascade; 
string path = "C:\\Users\\spj\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";
string change(int n)
{
	string res;
	if (n == 0) return "0";
	while (n>0)
	{
		res += n % 10 + 48;
		n /= 10;
	}
	string res2;
	for (int i = res.size() - 1; i >= 0; i--)
	{
		res2 += res[i];
	}
	return res2;
}
int changes(string x)
{
	int result = 0;
	for (int  i = 0; i <x.size(); i++)
	{
		result += x[i] - '0';
		result *= 10;
	}
	result /= 10;
	return result;
}
void qige(string str)
{
	Mat img = imread("E:\\"+str+".jpg");
	face_cascade.load(path);
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	face_cascade.detectMultiScale(img_gray, faces, 1.1, 3, CV_HAAR_DO_ROUGH_SEARCH, Size(50, 50));
	for (size_t j = 0; j < faces.size(); j++)
	{
		Mat faceROI = img(faces[j]);
		Mat myface;
		if (faceROI.cols > 100)
		{
			resize(faceROI, myface, Size(92, 112));
			string str = "E:\\xunlian\\"+change(x)+".jpg";
			x++;
			imwrite(str, myface);
		}
		waitKey(10);
	}
}
int main()
{
	for (int i = 0; i < 1000; i++)
	{
		if (i == 0)
		{
			qige("0");
		}
		string m = change(i);
		qige(m);
	}
	system("pause");
}

