import 'package:flutter/material.dart';

void main()
{
  runApp(MyApp());
}

class MyApp extends StatelessWidget{
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: "Container Design",
      theme: ThemeData(
        primaryColor: Colors.blue.shade50
      ),
      home: const AppDesign(),
    );
  }
}

class AppDesign extends StatelessWidget{
  const AppDesign({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        width: double.infinity,
        height: double.infinity,
        color: Colors.blue.shade50,
        child: Center(
          child: Container(
            height: 150,
            width: 150,
            decoration: BoxDecoration(
              color: Colors.blueGrey,
              // borderRadius: BorderRadius.circular(75)
              // borderRadius:const BorderRadius.only(bottomRight: Radius.circular(20), topLeft: Radius.circular(20)),
              border: Border.all(
                color: Colors.black26,
                width: 5
              ),
              boxShadow: const [BoxShadow(
                blurRadius: 90,
                spreadRadius: 11,
                color: Colors.grey,
              )],
              shape: BoxShape.circle
            ),
          ),
        ),
      ),
    );
  }

}