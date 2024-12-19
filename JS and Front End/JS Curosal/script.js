var divs = [
	{
		id: 1,
		title: "What is Lorem Ipsum?",
		content:
			"On the other hand, we denounce with righteous indignation and dislike men who are so beguiled and demoralized by the charms of pleasure of the moment, so blinded by desire",
		image: "images/1.webp",
	},
	{
		id: 2,
		title: "Why do we use it?",
		content:
			"At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium voluptatum deleniti atque corrupti quos dolores et quas molestias excepturi sint occaecati cupiditate non provident",
		image: "images/2.webp",
	},
	{
		id: 3,
		title: "Where does it come from?",
		content:
			"But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes,",
		image: "images/3.jpeg",
	},
	{
		id: 4,
		title: "Where can I get some?",
		content:
			"nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum",
		image: "images/4.webp",
	},
	{
		id: 5,
		title: "The standard Lorem Ipsum passage, used since the 1500s",
		content:
			"the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable",
		image: "images/5.jpg",
	},
	{
		id: 6,
		title: "1914 translation by H. Rackham",
		content:
			"There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour",
		image: "images/6.jpg",
	},
];

var container = document.querySelector(".container");

for (let index = 0; index < divs.length; index++) {
	const div = divs[index];

	var divElement = document.createElement("div");
	divElement.className = "card";
	divElement.id = div.id;

	var cardImage = document.createElement("div");
	cardImage.className = "card-image";

	var imgElement = document.createElement("img");
	imgElement.src = div.image;
	cardImage.appendChild(imgElement);

	var cardContent = document.createElement("div");
	cardContent.className = "card-content";

	var cardTitle = document.createElement("h3");
	cardTitle.innerText = div.title;

	var cardText = document.createElement("p");
	cardText.innerText = div.content;

	divElement.appendChild(cardImage);
	cardContent.appendChild(cardTitle);
	cardContent.appendChild(cardText);
	divElement.appendChild(cardContent);
	container.appendChild(divElement);

	imgElement.addEventListener("click", function () {
		showCard(div.id);
	});
}

function showCard(id) {
	var overlay = document.createElement("div");
	overlay.addEventListener("click", function (event) {
		if (event.target === overlay) {
			overlay.remove();
		}
		
	});
	overlay.classList.add("overly");
    overlay.id = id;

	var prevButton = document.createElement("span");
	prevButton.id = "prev";
	prevButton.classList.add("btn");
	prevButton.textContent = "Previous";

	prevButton.addEventListener("click", function () {
		goPrev(id);
	});

	var overlayContent = document.createElement("div");
	overlayContent.classList.add("overly-content");

	var image = document.createElement("img");
	image.src = divs[id - 1].image;

	overlayContent.appendChild(image);

	var nextButton = document.createElement("span");
	nextButton.id = "next";
	nextButton.classList.add("btn");
	nextButton.textContent = "Next";

	nextButton.addEventListener("click", function () {
		goNext(id);
	});

	overlay.appendChild(prevButton);
	overlay.appendChild(overlayContent);
	overlay.appendChild(nextButton);

	document.body.appendChild(overlay);

	overlay.addEventListener("click", function () {
		return;
	});
}

function goNext(id) {
	document.querySelector(".overly").remove();

	if (id < divs.length) {
		showCard(id + 1);
	} else {
		showCard(1);
	}
}
function goPrev(id) {
	document.querySelector(".overly").remove();

	if (id > 1) {
		showCard(id - 1);
	} else {
		showCard(divs.length);
	}
}

document.addEventListener("keyup", function (event) {
	var isOverlay = document.querySelector(".overly");
	if (!isOverlay) {
		return;
	}
	if (event.key === "Escape") {
		isOverlay.remove();
	}
	var id = +isOverlay.id

	if (event.key === "ArrowLeft") {
		goPrev(id);
	}

	if (event.key === "ArrowRight") {
		goNext(id);
	}
});
