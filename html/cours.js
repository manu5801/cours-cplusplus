window.onload=montre;
body.onclick=cacher_menu;


function montre(id) {
  var d = document.getElementById(id);
  var b = document.getElementById('bouton_menu');

  if (d) {
     if (d.style.display=='block') {
        d.style.display='none';
     }
     else
     {
		 d.style.display='block';
	 }
  }
  b.style.display='none';
}

function cacher_menu() {      
/*   if (IE) return;*/
   var m = document.getElementById('menu');
   var b = document.getElementById('bouton_menu');
   montre();
   if (m.style.display=='none') {
      m.style.display='block';
      b.style.display='none';
   } else {
      m.style.display='none';
      b.style.display='block';
   }
}    
function bckgrnd(couleur,id) {
   document.getElementById(id).style.background=couleur;
}


