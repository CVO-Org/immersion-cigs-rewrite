class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            // class Default;
            class Edit;                 // Default edit box (i.e. text input field)
            // class Combo;                // Default combo box (i.e. drop-down menu)
            // class Checkbox;             // Default checkbox (returned value is Boolean)
            // class CheckboxNumber;       // Default checkbox (returned value is Number)
            // class ModuleDescription;    // Module description
            // class Units;                // Selection of units on which the module is applied
        };

        // Description base classes (for more information see below):
        class ModuleDescription {
            // class AnyBrain;
        };
    };

    class EGVAR(aiCigs,module): Module_F {
        // Standard object definitions:
        scope = 2;                                                      // Editor visibility; 2 will show it in the menu, 1 will hide it.
        scopeCurator = 1;                                               // Zeus visibility
        displayName = ECSTRING(aiCigs,module_displayName);                   // Name displayed in the menu
        icon = QPATHTOEF(core,data\UI\light_cig.paa);    // Map icon. Delete this entry to use the default icon.
        category = QEGVAR(aiCigs,factionClass);

        function = QFUNC(aiCigs_module);        // Name of function triggered once conditions are met
        functionPriority = 10;                  // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
        isGlobal = 0;                           // 0 for server only execution, 1 for global execution, 2 for persistent global execution
        isTriggerActivated = 0;                 // 1 for module waiting until all synced triggers are activated
        isDisposable = 1;                       // 1 if modules is to be disabled once it is activated (i.e. repeated trigger activation will not work)
        is3DEN = 0;                             // 1 to run init function in Eden Editor as well
        curatorCanAttach = 0;                   // 1 to allow Zeus to attach the module to an entity

        // 3DEN Attributes Menu Options
        canSetArea = 0;                         // Allows for setting the area values in the Attributes menu in 3DEN
        canSetAreaShape = 0;                    // Allows for setting "Rectangle" or "Ellipse" in Attributes menu in 3DEN
        canSetAreaHeight = 0;                   // Allows for setting height or Z value in Attributes menu in 3DEN

        // Module attributes (uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific):
        class Attributes: AttributesBase {
            // Module-specific arguments:
            class EGVAR(aiCigs,west): Edit {
                displayName = "WEST";
                tooltip = ECSTRING(aiCigs,module_tooltip);
                property = QEGVAR(aiCigs,west);
                // Default text for the input box:
                defaultValue = "''"; // Because this is an expression, one must have a string within a string to return a string
            };
            class EGVAR(aiCigs,east): Edit {
                displayName = "EAST";
                tooltip = ECSTRING(aiCigs,module_tooltip);
                property = QEGVAR(aiCigs,east);
                // Default text for the input box:
                defaultValue = "''"; // Because this is an expression, one must have a string within a string to return a string
            };
            class EGVAR(aiCigs,guer): Edit {
                displayName = "GUER";
                tooltip = ECSTRING(aiCigs,module_tooltip);
                property = QEGVAR(aiCigs,guer);
                // Default text for the input box:
                defaultValue = "''"; // Because this is an expression, one must have a string within a string to return a string
            };
            class EGVAR(aiCigs,civ): Edit {
                displayName = "CIV";
                tooltip = ECSTRING(aiCigs,module_tooltip);
                property = QEGVAR(aiCigs,civ);
                // Default text for the input box:
                defaultValue = "''"; // Because this is an expression, one must have a string within a string to return a string
            };

            class ModuleDescription: ModuleDescription {}; // Module description should be shown last
        };


        // Module description (must inherit from base class, otherwise pre-defined entities won't be available)
        class ModuleDescription: ModuleDescription {
            description = "Defines classnames of pop or cigarettepackages to be allocated to each side.\nMultiple entries possible - seperated by ,";    // Short description, will be formatted as structured text
            sync[] = {};                // Array of synced entities (can contain base classes)
        };
    };
};
