import React, { Component } from "react";
import { connect } from "react-redux";
import { Field, reduxForm } from "redux-form";
import { createCliente } from "../actions/clientes";

class CadastroClientes extends Component {
    onSubmit(props) {
        this.props.createCliente(props, () => {
            // blog post has been created, navigate the user to the index
            // We navigate by calling this.props.history.push with the
            // new path to navigate to.
            this.props.history.push("/");
        });
    }
    renderField(field) {
        return (
            <div
                className={`form-group ${
                    field.meta.touched && field.meta.invalid ? "has-danger" : ""
                }`}>
                <label>{field.label}</label>
                <input {...field.input} type="text" className="form-control" />
                <div className="text-help">
                    {field.meta.touched ? field.meta.error : ""}
                </div>
            </div>
        );
    }

    render() {
        const { handleSubmit } = this.props;
        return (
            <form onSubmit={handleSubmit(this.onSubmit.bind(this))}>
                <h3>Cadastrar novo cliente</h3>
                <Field
                    label="Nome" // this is a custom prop
                    name="nome"
                    component={this.renderField}
                />
                <Field
                    label="Endereço" // this is a custom prop
                    name="endereco"
                    component={this.renderField}
                />
                <Field
                    label="Telefone"
                    name="phone"
                    component="input"
                    type="text"
                    placeholder="(xx)xxxxx-xxxx"
                />
                <button type="submit" className="btn btn-primary">
                    Submit
                </button>
            </form>
        );
    }
}

function validate(values) {
    const errors = {};

    if (!values.title) {
        errors.title = "Enter a username";
    }
    if (!values.categories) {
        errors.categories = "Enter categories";
    }
    if (!values.content) {
        errors.content = "Enter some content";
    }

    return errors;
}

// reduxForm: 1st is form config
// connect: first argument is mapStateToProps, 2nd is mapDispatchToProps
export default reduxForm({
    form: "ClientesNewForm",
    validate,
})(
    connect(
        null,
        { createCliente }
    )(CadastroClientes)
);
