# ue5reflectionparsereftool

If you need to parse member-variables into a text in Unreal Editor (for example, when editing some stats that are reflected in text) you can use `Source/Demo/StringParseTool`!

#### Usage
Create a derived from StringParseTool BP that has three pointers to the objects -- set them to pointers you want and change Description: resulting string will be in DescriptionPreview field.

#### Examples
See `Content/Demo/Task.uasset`, and 3 objects: `Source/Demo/ExampleObject1`, `Source/Demo/ExampleObject2`, `Content/Demo/ExampleObject3` Task points to!
