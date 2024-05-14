import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title:const Text('Card View'),
      ),
      body:const Center(
        child: Card(
          elevation: 20,
          shadowColor: Colors.greenAccent,
          color: Colors.green,
          child: Padding(
            padding: EdgeInsets.all(8.0),
            child: Text('Hello World', style: TextStyle(fontSize: 20, color: Colors.white),),
          ),
        ),
      )
    );
  }
}
