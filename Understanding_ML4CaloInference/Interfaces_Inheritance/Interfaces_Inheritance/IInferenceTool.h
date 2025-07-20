// Interface for InferenceTool
class IInferenceTool {
public:
    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual void preditc() = 0;
    virtual ~IInferenceTool() {} // Always add a virtual destructor to base interfaces
};

