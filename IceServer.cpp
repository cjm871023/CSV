
#include "demo.h"
#include <thread>


void HandleThread(const  AMD_Printer_printStringPtr &callback)
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
	callback->ice_response(111101,"fsad");
}
struct  PrinterImp : Printer {
	virtual   void  printString_async(
		const  AMD_Printer_printStringPtr &callback,
		const  string& s, const  Ice::Current&)
	{
		std::thread twork(HandleThread, callback);
		twork.detach();
		std::cout << "ret\n";
	}
};
int main()
{
	Ice::CommunicatorPtr ic = Ice::initialize();
	Ice::ObjectAdapterPtr adapter
		= ic->createObjectAdapterWithEndpoints("SP", "default -p 10000");
	Ice::ObjectPtr object = new  PrinterImp;
	adapter->add(object, ic->stringToIdentity("SimplePrinter"));

	adapter->activate();
	ic->waitForShutdown();
	return 0;
}

