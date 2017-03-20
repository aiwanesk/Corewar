from tkinter import *
import tkinter.filedialog as fdialog
from subprocess import Popen, PIPE, STDOUT
from threading import Thread
from queue import Queue, Empty
import os
import signal
import math
import time

DEBUG = False
ON_POSIX = 'posix' in sys.builtin_module_names

class New_Toplevel_1(Frame):
    def __init__(self, app, top=None):
        _bgcolor = '#d9d9d9'  # X11 color: 'gray85'
        _fgcolor = '#000000'  # X11 color: 'black'
        _compcolor = '#d9d9d9' # X11 color: 'gray85'
        _ana1color = '#d9d9d9' # X11 color: 'gray85'
        _ana2color = '#d9d9d9' # X11 color: 'gray85'

        self.top = top
        self.arr_file = []
        self.app = app

        self.top.geometry("880x747")
        self.top.title("Corewar - 42")
        self.top.configure(background="#d9d9d9")

        self.Frame1 = Frame(self.top)
        self.Frame1.place(relx=0.01, rely=0.01, relheight=0.85, relwidth=0.72)
        self.Frame1.configure(relief=GROOVE)
        self.Frame1.configure(borderwidth="2")
        self.Frame1.configure(relief=GROOVE)
        self.Frame1.configure(background="#d9d9d9")
        self.Frame1.configure(width=635)

        self.Canvas1 = Canvas(self.Frame1, width=635, height=635)
        self.Canvas1.place(relx=0.0, rely=0.0, relheight=0.99, relwidth=1.0)
        self.Canvas1.configure(background="white")
        self.Canvas1.configure(borderwidth="2")
        self.Canvas1.configure(insertbackground="black")
        self.Canvas1.configure(relief=RIDGE)
        self.Canvas1.configure(selectbackground="#c4c4c4")
        self.Canvas1.configure(selectforeground="black")
        self.Canvas1.pack(side=LEFT)

        self.run_vm = Button(self.top)
        self.run_vm.place(relx=0.24, rely=0.91, height=32, width=437)
        self.run_vm.configure(activebackground="#d9d9d9")
        self.run_vm.configure(activeforeground="#000000")
        self.run_vm.configure(background="#d9d9d9")
        self.run_vm.configure(foreground="#000000")
        self.run_vm.configure(highlightbackground="#d9d9d9")
        self.run_vm.configure(highlightcolor="black")
        self.run_vm.configure(text='''RUN VM''')
        self.run_vm.configure(width=437)

        self.Frame2 = Frame(self.top)
        self.Frame2.place(relx=0.75, rely=0.01, relheight=0.85, relwidth=0.24)
        self.Frame2.configure(relief=GROOVE)
        self.Frame2.configure(borderwidth="2")
        self.Frame2.configure(relief=GROOVE)
        self.Frame2.configure(background="#d9d9d9")
        self.Frame2.configure(width=200)

        self.Frame3 = Frame(self.Frame2)
        self.Frame3.place(relx=0.05, rely=0.03, relheight=0.21, relwidth=0.86)
        self.Frame3.configure(relief=GROOVE)
        self.Frame3.configure(borderwidth="2")
        self.Frame3.configure(relief=GROOVE)
        self.Frame3.configure(background="#d9d9d9")
        self.Frame3.configure(width=185)
        #TEST
        #self.Frame3.grid_columnconfigure(0, weight=1)
        #self.Frame3.grid_rowconfigure(0, weight=4)
        ##JOUEUR 1
        self.player1 = []
        self.playerName1 = StringVar()
        self.life1 = StringVar()
        self.player1.append(self.life1)
        self.player1.append(self.playerName1)
        x = Label(self.Frame3, textvariable=self.playerName1, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.4, relx=.5)
        x = Label(self.Frame3, textvariable=self.life1, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.55, relx=.5)

        self.Frame4 = Frame(self.Frame2)
        self.Frame4.place(relx=0.05, rely=0.27, relheight=0.21, relwidth=0.86)
        self.Frame4.configure(relief=GROOVE)
        self.Frame4.configure(borderwidth="2")
        self.Frame4.configure(relief=GROOVE)
        self.Frame4.configure(background="#d9d9d9")
        self.Frame4.configure(highlightbackground="#d9d9d9")
        self.Frame4.configure(highlightcolor="black")
        self.Frame4.configure(width=185)
        ##JOUEUR 2
        self.player2 = []
        self.playerName2 = StringVar()
        self.life2 = StringVar()
        self.player2.append(self.life2)
        self.player2.append(self.playerName2)
        x = Label(self.Frame4, textvariable=self.playerName2, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.4, relx=.5)
        x = Label(self.Frame4, textvariable=self.life2, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.55, relx=.5)


        self.Frame5 = Frame(self.Frame2)
        self.Frame5.place(relx=0.05, rely=0.51, relheight=0.21, relwidth=0.86)
        self.Frame5.configure(relief=GROOVE)
        self.Frame5.configure(borderwidth="2")
        self.Frame5.configure(relief=GROOVE)
        self.Frame5.configure(background="#d9d9d9")
        self.Frame5.configure(highlightbackground="#d9d9d9")
        self.Frame5.configure(highlightcolor="black")
        self.Frame5.configure(width=185)
        ##JOUEUR 3
        self.player3 = []
        self.playerName3 = StringVar()
        self.life3 = StringVar()
        self.player3.append(self.life3)
        self.player3.append(self.playerName3)
        x = Label(self.Frame5, textvariable=self.playerName3, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.4, relx=.5)
        x = Label(self.Frame5, textvariable=self.life3, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.55, relx=.5)


        self.Frame6 = Frame(self.Frame2)
        self.Frame6.place(relx=0.05, rely=0.76, relheight=0.21, relwidth=0.86)
        self.Frame6.configure(relief=GROOVE)
        self.Frame6.configure(borderwidth="2")
        self.Frame6.configure(relief=GROOVE)
        self.Frame6.configure(background="#d9d9d9")
        self.Frame6.configure(highlightbackground="#d9d9d9")
        self.Frame6.configure(highlightcolor="black")
        self.Frame6.configure(width=185)
        self.initMenu(self.top)
        ##JOUEUR 4
        self.player4 = []
        self.playerName4 = StringVar()
        self.life4 = StringVar()
        self.player4.append(self.life4)
        self.player4.append(self.playerName4)
        x = Label(self.Frame6, textvariable=self.playerName4, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.4, relx=.5)
        x = Label(self.Frame6, textvariable=self.life4, background="#d9d9d9")
        x.place(anchor=CENTER, rely=.55, relx=.5)

    def initMenu(self, top):
        self.menubar = Menu(top)
        top.config(menu=self.menubar)

        self.fileMenu = Menu(self.menubar)
        self.fileMenu.add_command(label="Add champion file", command = self.onOpen)
        self.fileMenu.add_command(label="Reset VM", command = self.onReset)
        self.menubar.add_cascade(label="Core", menu=self.fileMenu)

    def onOpen(self):
        self.arr_file.append(fdialog.askopenfilename(initialdir = ".", title = "Select file", filetypes = (("CORE files","*.cor"),("all files","*.*"))))

    def onReset(self):
        self.arr_file = []
        self.app.reset()

    def getFile(self):
        return self.arr_file

    def get_Canvas(self):
        return self.Canvas1

    def get_RunButton(self):
        return self.run_vm

    def get_player_by_id(self, id):
        if (id == 1):
            return self.player1
        if (id == 2):
            return self.player2
        if (id == 3):
            return self.player3
        if (id == 4):
            return self.player4

    def set_player_by_id(self, id, name="", life="0"):
        if (name != ""):
            self.get_player_by_id(id)[0].set("Name: " + name)
        self.get_player_by_id(id)[1].set("Life: " + life)

    def reset_label_champion(self, text=""):
        self.get_player_by_id(1)[0].set(text)
        self.get_player_by_id(2)[0].set(text)
        self.get_player_by_id(3)[0].set(text)
        self.get_player_by_id(4)[0].set(text)
        self.get_player_by_id(1)[1].set("")
        self.get_player_by_id(2)[1].set("")
        self.get_player_by_id(3)[1].set("")
        self.get_player_by_id(4)[1].set("")

    def update(self):
        self.top.update()

class App():
    def __init__(self):
        self.vp_start_gui()

        self.corewarRun = False

        #for the array
        self.memory_length = 4096 #mod here with header c
        self.nbline = 64
        self.size = 10
        self.array = [0 for i in range(self.memory_length)]
        self.color = {-1: "green", 0: "white", 1: "blue", 2: "red", 3: "yellow", 4: "cyan"}
        self.pcDict = {"1": 0};
        self.playerFrame = []

        self.process = None
        self.queue = None
        self.arr_file = []
        self.championString = ""

        if (len(sys.argv) > 1):
            a = len(sys.argv) - 1
            while (a > 0):
                self.arr_file.append(sys.argv[a])
                a = a - 1
            self.championString = ' '.join(self.arr_file)

    ## WINDOW
    def vp_start_gui(self):
        '''Starting point when module is the main routine.'''
        self.root = Tk()
        self.window = New_Toplevel_1 (top=self.root, app=self)
        #Untitled_support.init(self.root, top)
        self.window.reset_label_champion("Wait loading champion")
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

    def create_New_Toplevel_1(self, root, *args, **kwargs):
        '''Starting point when module is imported by another program.'''
        self.w = Toplevel (self.root)
        top = New_Toplevel_1 (top=self.w, app=self)

    def destroy_New_Toplevel_1(self):
        self.w.destroy()
        self.w = None

    def on_closing(self):
        self.corewarRun = False
        time.sleep(1)
        self.reset()
        self.root.destroy()

    ##END WINDOW

    def run(self):
        self.display()
        self.window.get_RunButton().configure(command=self.run_vm)

    def display(self):
        canvasx = int(self.window.get_Canvas().cget("width")) / self.nbline
        canvasy = int(self.window.get_Canvas().cget("height")) / int((len(self.array) / self.nbline))
        canvas_ceil_x = canvasx - 0.4
        canvas_ceil_y = canvasy - 0.4
        for a in range(len(self.array)):
            y = int(a / int(len(self.array) / self.nbline))
            ytmp =  canvas_ceil_y * y
            y0 = canvas_ceil_y + ytmp
            y1 = canvas_ceil_y + canvas_ceil_y + ytmp
            x = int(a % (len(self.array) / self.nbline))
            x0 = x * canvas_ceil_x + canvas_ceil_x
            x1 = x * canvas_ceil_x + canvas_ceil_x + canvas_ceil_x
            self.window.get_Canvas().create_rectangle(x0, y0, x1, y1, fill = self.color[self.array[a]]);
        self.root.update()

    def unit_display(self, a, color=0):
        canvasx = int(self.window.get_Canvas().cget("width")) / self.nbline
        canvasy = int(self.window.get_Canvas().cget("height")) / int((len(self.array) / self.nbline))
        canvas_ceil_x = canvasx - 0.4
        canvas_ceil_y = canvasy - 0.4
        y = int(a / int(len(self.array) / self.nbline))
        ytmp =  canvas_ceil_y * y
        y0 = canvas_ceil_y + ytmp
        y1 = canvas_ceil_y + canvas_ceil_y + ytmp
        x = int(a % (len(self.array) / self.nbline))
        x0 = x * canvas_ceil_x + canvas_ceil_x
        x1 = x * canvas_ceil_x + canvas_ceil_x + canvas_ceil_x
        if (color == 0):
            test = self.color[self.array[a]]
        else:
            test = "green";
        self.window.get_Canvas().create_rectangle(x0, y0, x1, y1, fill = test)
        self.root.update()

    def run_vm(self):
        if (self.corewarRun == True):
            return
        if (self.corewarRun != True):
            self.window.reset_label_champion("")
            self.window.update()
            if self.championString == "":
                self.championString = ' '.join(self.window.getFile())
        if (DEBUG and self.championString == ""):
            self.championString = "/Users/mbarbari/project/corewar/ui/ressources/3615sleep.cor /Users/mbarbari/project/corewar/ui/ressources/3615sleep.cor"
        if (len(self.championString.split( )) > 4):
            print("To many champion")
            self.reset()
        elif (self.corewarRun != True and self.championString != ""):
            try: pathcore = os.environ["COREWAR"]
            except : pathcore = "./"
            if (os.path.isfile(pathcore + "/corewar") and  os.access(pathcore + "/corewar", os.X_OK)):
                execute = pathcore + "./corewar -ui -n 0 " + self.championString
                self.corewarRun = True
                try: self.process = Popen(execute, stdout = PIPE, stderr = STDOUT, shell=True)
                except:
                    print("Executable does not exists")
                else :
                    self.setprocess_stdout()
            else:
                print("Executable cannot find")
        self.pcDict = {"1": 0}

    def enqueue_output(self, out, queue):
        for line in iter(out.readline, b''):
            if (self.corewarRun == False):
                break ;
            newline = line.decode("utf-8")
            if ("UI_PROTOCOL" in newline):
                queue.put(newline)
        out.close()

    def process_data(self):
        while (self.corewarRun):
            try: line = self.queue.get_nowait()
            except Empty:
                pass
            else:
                out = line.split( )
                if (len(out) > 1 and out[0] == "UI_PROTOCOL"):
                    if (out[1] == "LMZ"): #"UI_PROTOCOL LMZ 1-0-588-0.t" give ID-StartPtr-LengthCode-Name
                        self.setprocess_lmz(out[2])
                        self.display()
                    if (out[1] == "PC"): #"UI_PROTOCOL PC 1-255" give ID-PtrMemory
                        self.setprocess_pc(out[2])
                    if (out[1] == "MEM"): #"UI_PROTOCOL MEM 1-255" give ID-PtrMemory
                        self.setprocess_memory(out[2])
                    if (out[1] == "LC"): #"UI_PROTOCOL LC 1-21-1480" give ID-Life-Cycle
                        self.setprocess_life_cycle(out[2])
                        self.root.update()
                    if (out[1] == "WIN"): #"UI_PROTOCOL WIN 1" give ID
                        self.setprocess_win(out[2])
                        self.root.update()
                if (self.corewarRun == False):
                    self.queue.queue.clear()
                    break

    def setprocess_stdout(self):
        self.queue = Queue()
        self.thread = Thread(target=self.enqueue_output, args=(self.process.stdout, self.queue))
        self.thread.daemon = True
        self.thread.start()
        self.process_data()

    def setprocess_lmz(self, command):
        out = command.split("-")
        id = int(out[0]) + 1
        for index in range(len(self.array)):
            if (index >= int(out[1]) and index <= (int(out[1]) + int(out[2]))):
                self.array[index] = id
        self.window.set_player_by_id(id, out[3], "0")

    def setprocess_win(self, command):
        id  = int(command) + 1
        self.window.get_player_by_id(id)[1].set("WINNER")
        if (self.process.poll() is not None):
            self.corewarRun = False

    def setprocess_pc(self, command):
        out = command.split("-")
        id = int(out[0]) + 1
        if out[0] in self.pcDict.keys():
            self.unit_display(self.pcDict[out[0]])
        self.unit_display(int(out[1]), 1)
        self.pcDict[out[0]] = int(out[1])

    def setprocess_memory(self, command):
        out = command.split("-")
        id = int(out[0]) + 1
        for index in range(len(self.array)):
            if (index == int(out[1])):
                self.array[index] = id
                self.unit_display(int(out[1]))

    def setprocess_life_cycle(self, command):
        out = command.split("-")
        id = int(out[0]) + 1
        self.window.get_player_by_id(id)[1].set("Life: " + out[1])

    def loop(self):
        self.root.mainloop()

    def reset(self):
        self.championString = ""
        for index in range(len(self.array)):
            self.array[index] = 0
        if (self.process is not None):
            self.process.kill()
        self.corewarRun = False
        self.window.reset_label_champion("Wait loading champion")
        if (self.queue is not None):
            self.queue.queue.clear()
        self.display()

try :
    application = App()
    application.run()
    application.loop()
except :
    pass
