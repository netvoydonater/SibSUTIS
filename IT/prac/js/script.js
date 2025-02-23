var ElementScrollAboutUs = document.getElementById("about_us")

var ButAboutUs = document.querySelector(".aboutUs")

function ScrollAboutUs()
{
    ElementScrollAboutUs.scrollIntoView({block : "center", behavior : "smooth"});
}

ButAboutUs.addEventListener("click", ScrollAboutUs);

var ElementScrollContacts = document.getElementById("contacts")

var ButContacts = document.querySelector(".ContActs")

function ScrollContacts()
{
    ElementScrollContacts.scrollIntoView({block : "center", behavior : "smooth"});
}

ButContacts.addEventListener("click", ScrollContacts);



