var todos = [];
var current_todo = null;

var titleElement = document.getElementById("title");
var description = document.getElementById("description");
var SaveButton = document.getElementById("add");
var ErrorLabelOfDescription = document.getElementById("error");
var DoneButton = document.getElementsByClassName("done");
SaveButton.addEventListener("click", addOrUpdateTodo);

var ListOfTodos = document.getElementsByClassName("list")[0];
var Search = document.getElementsByClassName("search")[0];
var SearchLabel = document.getElementById("searchLabel");



Search.addEventListener("keyup", function () {
	var query = Search.value.trim();
	RemoveAllCards();

	if (query === "" ) {
		SearchLabel.innerHTML = "All Todos";
		for (var i = 0; i < todos.length; i++) {
			createCard(todos[i].title);
		}
	} else {
		var todo = searchTodo(query);
		if (todo) {
			SearchLabel.innerHTML = `Search results for "${query}"`;
			createCard(todo.title);
		} else {
			SearchLabel.innerHTML = `No results found for "${query}"`;
			for (var i = 0; i < todos.length; i++) {
				createCard(todos[i].title);
			}
		}
	}
});

description.addEventListener("keyup", function () {
	if (description.value.length < 20) {
		ErrorLabelOfDescription.innerHTML =
			"Description must be at least 20 characters";
	} else {
		ErrorLabelOfDescription.innerHTML = "";
	}
});

function addOrUpdateTodo() {
	if (titleElement.value === "" || titleElement.value === "") {
		alert("Please fill in the title and description");
		return;
	}

	if (titleElement.value.length < 6) {
		alert("Please fill in the title with at least 6 characters");
		return;
	}

	var todo = {
		title: title.value,
		description: description.value,
		status: "pending",
	};
	if (current_todo != null) {
		var card = ListOfTodos.children[current_todo];
		card.querySelector("h2").innerHTML = todo.title;

		current_todo = null;
	} else {
		todos.push(todo);
		createCard(todo.title);
	}
	titleElement.value = "";
	description.value = "";
}

function searchTodo(title) {
	for (var i = 0; i < todos.length; i++) {
		if (todos[i].title === title) {
			return todos[i];
		}
	}
}

function MarkAsCompleted(card, index) {
	card.classList.add("completed");
	todos[index].status = "completed";
	
}

function createCard(title) {
	var index = todos.length - 1;
	var card = document.createElement("div");
	card.classList.add("card");

	if (todos[index].status === "completed") {
		card.classList.add("completed");
	}

	var h2 = document.createElement("h2");
	h2.innerHTML = title;
	card.appendChild(h2);

	var actions = document.createElement("div");
	actions.classList.add("actions");

	var deleteButton = document.createElement("button");
	deleteButton.classList.add("delete");
	deleteButton.innerHTML = "Delete";

    deleteButton.addEventListener("click", function () {
        for (var i = 0; i < ListOfTodos.children.length; i++) {
            if (ListOfTodos.children[i] === card) {
                ListOfTodos.removeChild(card);
                todos.splice(i, 1);
                break;
            }
        }
    });

	var doneButton = document.createElement("button");
	doneButton.classList.add("done");
	doneButton.innerHTML = "Done";


	doneButton.addEventListener("click", function () {
		MarkAsCompleted(card, index);
		doneButton.disabled = true;
		
	});

	var editButton = document.createElement("button");
	editButton.innerHTML = "Edit";
    editButton.classList.add("edit");

	editButton.addEventListener("click", function () {
		for (var i = 0; i < ListOfTodos.children.length; i++) {
			if (ListOfTodos.children[i] === card) {
				current_todo = i;
				titleElement.value = todos[i].title;
				description.value = todos[i].description;
				break;
			}
		}
	});

	

	actions.appendChild(deleteButton);
	actions.appendChild(doneButton);
	actions.appendChild(editButton);

	card.appendChild(actions);

	ListOfTodos.appendChild(card);
}
function RemoveAllCards() {
	ListOfTodos.innerHTML = ""; 
}
