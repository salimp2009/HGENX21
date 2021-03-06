#pragma once

namespace Hgenx
{
	enum class ShaderDataType
	{
		None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:		return 4;
		case ShaderDataType::Float2:	return 4 * 2;
		case ShaderDataType::Float3:	return 4 * 3;
		case ShaderDataType::Float4:	return 4 * 4;
		case ShaderDataType::Mat3:		return 4 * 3 * 3;
		case ShaderDataType::Mat4:		return 4 * 4 * 4;
		case ShaderDataType::Int:		return 4;
		case ShaderDataType::Int2:		return 4 * 2;
		case ShaderDataType::Int3:		return 4 * 3;
		case ShaderDataType::Int4:		return 4 * 4;
		case ShaderDataType::Bool:		return 1;
		}

		HG_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		std::string Name;
		ShaderDataType Type;
		std::uint32_t Size;
		std::size_t Offset;
		bool Normalized;

		BufferElement() = default;

		BufferElement(ShaderDataType type, std::string name, bool normalized=false )
			: Name{std::move(name)}, Type{type}, Size{ShaderDataTypeSize(type)}, Offset{0}, Normalized{normalized} {}

		uint32_t GetComponentCount() const
		{
			switch (Type)
			{
			case ShaderDataType::Float:		return 1;
			case ShaderDataType::Float2:	return 2;
			case ShaderDataType::Float3:	return 3;
			case ShaderDataType::Float4:	return 4;
			case ShaderDataType::Mat3:		return 3 * 3;  // TODO: change this to return 3;  // 3 * float3
			case ShaderDataType::Mat4:		return 4 * 4;  // TODO: change this to return 4;  // 4 * float4
			case ShaderDataType::Int:		return 1;
			case ShaderDataType::Int2:		return 2;
			case ShaderDataType::Int3:		return 3;
			case ShaderDataType::Int4:		return 4;
			case ShaderDataType::Bool:		return 1;
			}

			HG_CORE_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		}

	};

	class BufferLayout
	{
	public:
		// TODO; incomplete!!




	private:
		std::vector<BufferElement>m_Elements;
		std::uint32_t m_Stride;
	};


	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		/*TODO; will be implemented */
		//virtual const BufferLayout& GetLayout() const& = 0;
		//virtual void SetLayout(const BufferLayout& layout) = 0;

		/*TODO; Will be implemented*/
		static VertexBuffer* Create(float* vertices, std::uint32_t size);
		//static Ref<VertexBuffer> Create(float* vertices, uint32_t size);

	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual std::uint32_t GetCount() const = 0;

		/*TODO; Will be implemented*/
		static IndexBuffer* Create(std::uint32_t* indices, std::uint32_t count);
		//static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);  //TODO: Change above to Ref<> (shared pointer)

	};




} // endof namespace