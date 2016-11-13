# xinput-disable-guide
A quick wrapper DLL that stops apps from detecting when the Xbox controller's guide button is pressed. Originally created to prevent Steam from opening Big Picture mode or making itself frontmost whenever the guide button is pressed, as Steam has no option for turning off this behavior for some reason. Could also be used to customize Xinput behavior for other 32-bit apps with some minimal changes.

To create the DLLs, build the included Visual Studio projects. These projects were created with [genwrapper](https://github.com/floodyberry/genwrapper) which is a bit old and consequently only works for 32-bit DLLs. So no 64-bit support right now. (Note that this was originally created for Steam and Steam is 32-bit.)

### Possible future work:
Use different wrapper technique that works for both 32-bit and 64-bit.

Factor out the (admittedly minimal) shared logic between the two versions of the DLLs so that it's easier to fork and change the behavior of the DLL.