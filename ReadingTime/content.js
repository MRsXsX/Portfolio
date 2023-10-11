
article = document.querySelector("body");
if(article){
const text = article.textContent;
const words = text.matchAll(/[^\s]+/g);
const count = [...words].length;
const ReadTime = Math.round(count/200);
const badge = document.createElement("p");
badge.classList.add("color-secondary-text", "type--caption");
badge.textContent = `Reading Time ${ReadTime} min`;
h = document.querySelector("h1");
date = document.querySelector("time")?.parentNode;
(date ?? h ).insertAdjacentElement("afterend",badge);
}
