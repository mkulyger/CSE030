$(document).ready(function(){
    $("#button").click(function(){
        var x = $("#lhs").val();
        var y = $("#rhs").val();

        $.get("/Add", {"x": x, "y": y}, function(response){
            $("#ans").html(response);
        });
    });
   
    $("#button2").click(function(){
        var x = $("#lhs").val();
        var y = $("#rhs").val();
    $.get("/Subtract", {"x": x, "y": y}, function(response){
        $("#ans").html(response);
});
    });

    $("#button3").click(function(){
        var x = $("#lhs").val();
        var y = $("#rhs").val();
    $.get("/Multiply", {"x": x, "y": y}, function(response){
        $("#ans").html(response);
});
    });

$("#button4").click(function(){
    var x = $("#lhs").val();
    var y = $("#rhs").val();
$.get("/Divide", {"x": x, "y": y}, function(response){
    $("#ans").html(response);
                
                });
            });
});