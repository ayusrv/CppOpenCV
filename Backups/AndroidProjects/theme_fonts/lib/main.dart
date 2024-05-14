import 'package:flutter/material.dart';
import 'package:theme_fonts/uihelper/headline_one.dart';

void main(){
  runApp(MyApp());
}

class MyApp extends StatelessWidget{
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "ThemeApp",
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primarySwatch: Colors.blue, // Add a comma here
        textTheme: const TextTheme(
          displayLarge: TextStyle(fontSize: 21, fontWeight: FontWeight.w500),
          displayMedium: TextStyle(fontSize: 11, fontWeight: FontWeight.w400),
          // Define your additional subtitle styles here
          // subtitle1: const TextStyle(fontSize: 16, fontWeight: FontWeight.w400),
          // subtitle2: const TextStyle(fontSize: 14, fontWeight: FontWeight.w300, color: Colors.grey),
          // Add more subtitle styles as needed
          titleSmall: TextStyle(fontSize: 12, fontWeight: FontWeight.w600),
        )
      ),
      home:const MyAppWidget(),
    );
  }
}

class MyAppWidget extends StatelessWidget{
  const MyAppWidget({Key? key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).primaryColor,
        title:const Text("ThemeApp"),
      ),
      body: Column(
        children: [
          Padding(
            padding:const EdgeInsets.all(8.0),
            child: Text('first data', style: Theme.of(context).textTheme.displayLarge),
          ),
          Text('first data',style: Theme.of(context).textTheme.displayMedium),
          Padding(
            padding:const EdgeInsets.all(8.0),
            child: Text('first data', style: Theme.of(context).textTheme.displayLarge!.copyWith(color: Colors.orange)),
          ),
          Text('first data',style: Theme.of(context).textTheme.displayMedium),
          Padding(
            padding:const EdgeInsets.all(8.0),
            child: Text('first data', style: headline_one()),
          ),
          Text('first data',style: Theme.of(context).textTheme.displayMedium),

        ],
      ),
    );

  }

}
