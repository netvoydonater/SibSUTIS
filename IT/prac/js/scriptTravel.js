
var ElementScrollCountry = document.getElementById("Country")
var ButCountry = document.querySelector(".countrybut")
function ScrollCountry()
{
    ElementScrollCountry.scrollIntoView({block : "center", behavior : "smooth"});
}
ButCountry.addEventListener("click", ScrollCountry);


var ElementScrollService = document.getElementById("OurService")
var ButService = document.querySelector(".servicedut")
function ScrollService()
{
    ElementScrollService.scrollIntoView({block : "center", behavior : "smooth"});
}
ButService.addEventListener("click", ScrollService);


var ElementScrollReviews = document.getElementById("Reviews")
var ButReviews = document.querySelector(".reviewbut")
function ScrollReviews()
{
    ElementScrollReviews.scrollIntoView({block : "center", behavior : "smooth"});
}
ButReviews.addEventListener("click", ScrollReviews);    


var ElementScrollContacts = document.getElementById("contactsour")
var ButContacts = document.querySelector(".contactsbut")
function ScrollContacts()
{
    ElementScrollContacts.scrollIntoView({block : "center", behavior : "smooth"});
}
ButContacts.addEventListener("click", ScrollContacts);