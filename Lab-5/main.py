from Node import *

from kivy.app import App
from kivy.uix.boxlayout import BoxLayout

from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button

output = Label(text="Output", font_size="20")

class Main:
	root = None

main = Main()

class MyApp(App):
	def build(self):
		bl = BoxLayout(orientation="horizontal")

		control = BoxLayout(orientation="vertical")

		trv = BoxLayout(orientation="horizontal")
		init = BoxLayout(orientation="horizontal")
		add = BoxLayout(orientation="horizontal")
		rm = BoxLayout(orientation="horizontal")
		srch = BoxLayout(orientation="horizontal")

		# self.output = output

		init.add_widget( Button(text="Init", on_press=self.pressInit, background_color=[.4, .8, .4, 1], font_size="20") )
		self.init_inp = TextInput(input_type="number")
		init.add_widget(self.init_inp)

		add.add_widget( Button(text="Add", on_press=self.pressAdd, background_color=[.4, .8, .4, 1], font_size="20") )
		self.add_inp = TextInput(input_type="number")
		add.add_widget(self.add_inp)

		rm.add_widget( Button(text="Remove", on_press=self.pressRemove, background_color=[.4, .8, .4, 1], font_size="20") )
		self.rm_inp = TextInput(input_type="number")
		rm.add_widget(self.rm_inp)

		srch.add_widget( Button(text="Search", on_press=self.pressSearch, background_color=[.4, .8, .4, 1], font_size="20") )
		self.srch_inp = TextInput(input_type="number")
		srch.add_widget(self.srch_inp)

		trv.add_widget( Button(text="Inorder", on_press=self.pressInorder, background_color=[.4, .8, .4, 1], font_size="20") )
		trv.add_widget( Button(text="Preorder", on_press=self.pressPreorder, background_color=[.4, .8, .4, 1], font_size="20") )
		trv.add_widget( Button(text="Postorder", on_press=self.pressPostorder, background_color=[.4, .8, .4, 1], font_size="20") )
		trv.add_widget( Button(text="Levels", on_press=self.pressLevels, background_color=[.4, .8, .4, 1], font_size="20") )

		control.add_widget(init)
		control.add_widget(add)
		control.add_widget(rm)
		control.add_widget(srch)
		control.add_widget(trv)

		bl.add_widget(control)
		bl.add_widget(output)

		return bl

	def pressInit(self, instance):
		val = self.init_inp.text
		if (val == ""):
			val = 0

		main.root = Node( int(val) )

		output.text = str(main.root.data)
		self.init_inp.text = ""

	def pressAdd(self, instance):
		val = self.add_inp.text
		if (val == ""):
			val = 0

		main.root.insert( int(val) )
		self.add_inp.text = ""

	def pressRemove(self, instance):
		val = self.rm_inp.text
		if (val == ""):
			val = 0

		main.root.deleteNode( int(val) )
		self.rm_inp.text = ""

	def pressSearch(self, instance):
		val = self.srch_inp.text
		if (val == ""):
			val = 0

		output.text = "Searching for " + str(val) + "\n"
		out = main.root.findPath( int(val) )
		if (out):
			output.text += str(out)
		else:
			output.text += "Nothing has been found"

		self.srch_inp.text = ""

	def pressInorder(self, instance):
		output.text = "Inorder\n"
		output.text += str(main.root.inorder())

	def pressPostorder(self, instance):
		output.text = "Postorder\n"
		output.text += str(main.root.postorder())

	def pressPreorder(self, instance):
		output.text = "Preorder\n"
		output.text += str(main.root.preorder())

	def pressLevels(self, instance):
		output.text = "Levels\n"
		# output.text += str(main.root.postorder())
		# print(main.root.printLevelOrder())
		out = main.root.printLevelOrder()

		i = 0
		for x in out:
			output.text += "Level " + str(i) + ": "
			for z in x:
				output.text += str(z) + " "
			output.text += "\n"
			i += 1


if __name__ == '__main__':
	MyApp().run()
