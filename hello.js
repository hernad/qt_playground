button.text = 'Husremović';

button.styleSheet = 'font-style: italic';
button.show();

var i=0;

button2.show();

button.clicked.connect(onButtonClicked);   

function onButtonClicked() {
  switch(button.text) {
	  case "Ernad":
		 button.text = "Husremović";
		 break;
	  case "Husremović":
		 button.text = "Ernad";
		 break;
  }

  i += 1;
  button2.text = i; 

}


