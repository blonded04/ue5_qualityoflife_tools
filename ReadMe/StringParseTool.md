# StringParseTool

If you need to parse member-variables into a text in Unreal Editor (for example, when editing some stats that are reflected in text) you can use [StringParseTool](../Source/Demo/StringParseTool.h) header!

#### Usage
Create a derived from StringParseTool BP that has three pointers to the objects, which are derived classes from [MyObjejct](../Source/Demo/MyObjejct.h) — set them to pointers you want and change Description: resulting string will be in DescriptionPreview field.

#### Examples
See [Task](../Content/Demo/StringParseToolExample.uasset), and 3 objects: [ExampleObject1](../Source/Demo/ExampleObject1.h), [ExampleObject2](../Source/Demo/ExampleObject2.h), [ExampleObject3](../Content/Demo/ExampleObject3.uasset) Task points to!
